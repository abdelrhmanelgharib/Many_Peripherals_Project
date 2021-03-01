/*
 * TIMER0_prog.c
 *
 *  Created on: Feb 20, 2021
 *  Author: Kariman
 */

#include "../../LIB/STD_types.h"

#include "../../LIB/BIT_Math.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "avr/interrupt.h"
#include "TIMER0_Interface.h"
#include "../../MCAL/DIO/Memmap.h"


static void (*OVCallBackptr)(void);
static void (*CTCCallBackptr)(void);

static u32 OverflowNumber =0;
static u8 Preload =0;

void TIMER0_void_Intialize(timerMode_type mode , prescaller_type prescaller , timerOC0_type OC0_type )
{
	// step one :mode selction
	switch(mode)
	{
	case TIMER0_NORMAL_MODE:
		CLRBIT(TCCR0,WGM00);
		CLRBIT(TCCR0,WGM01);
	break;
	case TIMER0_CTC_MODE:
		CLRBIT(TCCR0,WGM00);
		SETBIT(TCCR0,WGM01);
	break;
	case TIMER0_FASTPWM_MODE:
		SETBIT(TCCR0,WGM00);
		SETBIT(TCCR0,WGM01);
	break;
	case TIMER0_PHASECORRECT_MODE:
		SETBIT(TCCR0,WGM00);
		CLRBIT(TCCR0,WGM01);
	break;
	}

	// step 2 :Prescaller selction
	TCCR0 &= 0xf8;
	TCCR0 |= prescaller;

	// step 3 :OC0Pin mode selction
	TCCR0 &= 0b11001111;
	TCCR0 |=(OC0_type<<4);


}//end TIMER0_void_Intialize
////////////////////////////////////////////////////////////////////////////////////////////////////////
void TIMER0_void_TimerStop(void)
{
	TCCR0 &= 0xf8;//0b1111 1100
}//end TIMER0_void_TimerStop
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void TIMER0_void_TimerStart(prescaller_type prescaller)
{
	TCCR0 &= 0xf8;
	TCCR0 |= prescaller;
}//end TIMER0_void_TimerStart
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void TIMER0_void_EnableOVInt(void)
{
	SETBIT(SREG, SREG_I);
	SETBIT(TIMSK, TOIE0);

}//end TIMER0_void_EnableOVInt
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void TIMER0_void_DisableOVInt(void)
{
	CLRBIT(TIMSK,TOIE0);

}//end TIMER0_void_DisableOVInt
////////////////////////////////////////////////////////////////////////////////////////////////////////
void TIMER0_void_SetOVCALLBack(void(*copy_ptr)(void))
{
	OVCallBackptr = copy_ptr  ;

}//end TIMER0_void_SetOVCALLBack
////////////////////////////////////////////////////////////////////////////////////////////////////////
void TIMER0_void_EnableCTCInt(void)
{
	SETBIT(SREG,7);
	SETBIT(TIMSK,OCIE0);

}//end TIMER0_void_EnableCTCInt
////////////////////////////////////////////////////////////////////////////////////////////////////////
void TIMER0_void_DisableCTCInt(void)
{
	CLRBIT(TIMSK,OCIE0);

}//end TIMER0_void_DisableCTCInt
////////////////////////////////////////////////////////////////////////////////////////////////////////
void TIMER0_void_SetCTCCALLBack(void(*copy_ptr)(void))
{
	CTCCallBackptr = copy_ptr  ;

}//end TIMER0_void_SetCTCCALLBack
////////////////////////////////////////////////////////////////////////////////////////////////////////
void TIMER0_void_SetCompareValue(u8 Copy_CompValue)
{
	OCR0 = Copy_CompValue;

}//end TIMER0_void_SetCompareValue
////////////////////////////////////////////////////////////////////////////////////////////////////////
void TIMER0_void_SetDesiredTime_MicroSec(u32 copy_time,prescaller_type Copy_prescaller)// as delay Fun.
{
	u16 prescaller;
	switch(Copy_prescaller)
	{
	case NO_Prescaller:
		prescaller = 1;
	break;
	case Prescaller_8:
			prescaller = 8;
	break;
	case Prescaller_64:
			prescaller = 64;
	break;
	case Prescaller_256:
			prescaller = 256;
	break;
	case Prescaller_1024:
			prescaller = 1024;
	break;


	}
	u32 TickTime =(prescaller * 1000000) / TIMER0_F_CPU;
	u32 OverFlowTime = TickTime *TIMER0_REG_CABACITY;
	u32 DesiredTime = copy_time;

	OverflowNumber = DesiredTime / OverFlowTime;
	u32 OverFlowRemTime = DesiredTime % OverFlowTime;
	u32 OverFlowRemCounts = ((float)OverFlowRemTime/OverFlowTime)*TIMER0_REG_CABACITY;

	TCNT0=0;
	if(OverFlowRemTime>0)
	{
		Preload = TIMER0_REG_CABACITY - OverFlowRemCounts;
		TCNT0 = Preload;
		OverflowNumber++;
	}
}// end TIMER0_void_SetDesiredTime_MicroSec
////////////////////////////////////////////////////////////////////////////////////////////////////////
void TIMER0_void_FastPWM(u8 copy_DutyCycle ,timerOC0_type OC0_type,prescaller_type prescaller )
{
	switch(OC0_type)
	{
	case TIMER0_NONINVERTING_PWM_OC0:
		OCR0 = ((copy_DutyCycle*256)/100)-1;
	break;
	case TIMER0_INVERTING_PWM_OC0:
		OCR0 = 255-((copy_DutyCycle*256)/100);
	break;
	default:
	return;
	}
	TIMER0_void_TimerStart(prescaller);
}//end TIMER0_void_FastPWM
////////////////////////////////////////////////////////////////////////////////////////////////////////
void TIMER0_void_PhaseCorrectPWM(u8 copy_DutyCycle ,timerOC0_type OC0_type )
{
	switch(OC0_type)
	{
	case TIMER0_NONINVERTING_PWM_OC0:
		OCR0 = ((copy_DutyCycle*255)/100);
	break;
	case TIMER0_INVERTING_PWM_OC0:
		OCR0 = 255-((copy_DutyCycle*255)/100);
	break;
	default:
		return;
	}
}// end TIMER0_void_PhaseCorrectPWM

u32 TIMER0_void_TIMER0_TickTime(prescaller_type prescaler)
{
	switch(prescaler)
	{
	case NO_Prescaller:
		prescaler = 1;
		break;
	case Prescaller_8:
			prescaler = 8;
		break;
	case Prescaller_64:
			prescaler = 64;
		break;
	case Prescaller_256:
			prescaler = 256;
		break;
	case Prescaller_1024:
			prescaler = 1024;
		break;

	}

	u32 TickTime = prescaler/TIMER0_F_CPU;
	return TickTime;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
//ISR(TIMER0_OVF_vect)
//{
//	static u32 counter =0;
//	counter++;
//	if(counter == OverflowNumber)
//	{
//		TCNT0 = Preload;
//		counter =0;
//		OVCallBackptr();
//	}
//}
// end ISR
////////////////////////////////////////////////////////////////////////////////////////////////////////


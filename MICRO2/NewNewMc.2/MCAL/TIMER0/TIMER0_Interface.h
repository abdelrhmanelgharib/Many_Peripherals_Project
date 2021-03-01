/*
 * TIMER_Interface.h
 *
 *  Created on: Feb 20, 2021
 *  Author: Kariman
 */
#ifndef MCAL_TIMER0_TIMER_INTERFACE_H_
#define MCAL_TIMER0_TIMER_INTERFACE_H_


#define  TIMER0_F_CPU   8000000UL
#define TIMER0_REG_CABACITY  256


typedef enum
{
	NO_Prescaller =1       ,
	Prescaller_8          ,
	Prescaller_64          ,
	Prescaller_256         ,
	Prescaller_1024        ,
	Prescaller_Fall_EXT_Clk,
	Prescaller_Rais_EXT_Clk,
}prescaller_type;

typedef enum
{
	TIMER0_NORMAL_MODE      ,
	TIMER0_CTC_MODE         ,
	TIMER0_FASTPWM_MODE     ,
	TIMER0_PHASECORRECT_MODE,
}timerMode_type;

typedef enum
{
	TIMER0_DISCONNECT_OC0=0,
	TIMER0_TOGGLE_OC0      ,
	TIMER0_CLEAR_OC0       ,
	TIMER0_SET_OC0         ,

	TIMER0_NONINVERTING_PWM_OC0=2,
	TIMER0_INVERTING_PWM_OC0
}timerOC0_type;


void TIMER0_void_Intialize(timerMode_type mode , prescaller_type prescaller , timerOC0_type OC0_type );
void TIMER0_void_TimerStop(void);
void TIMER0_void_TimerStart(prescaller_type prescaller);

void TIMER0_void_EnableOVInt(void);
void TIMER0_void_DisableOVInt(void);
void TIMER0_void_SetOVCALLBack(void(*copy_ptr)(void));

void TIMER0_void_EnableCTCInt(void);
void TIMER0_void_DisableCTCInt(void);
void TIMER0_void_SetCTCCALLBack(void(*copy_ptr)(void));

void TIMER0_void_SetCompareValue(u8 Copy_CompValue);
void TIMER0_void_SetDesiredTime_MicroSec(u32 copy_time,prescaller_type Copy_prescaller);// as delay Fun.

void TIMER0_void_FastPWM(u8 copy_DutyCycle ,timerOC0_type OC0_type,prescaller_type prescaller  );
void TIMER0_void_PhaseCorrectPWM(u8 copy_DutyCycle ,timerOC0_type OC0_type );

u32 TIMER0_void_TIMER0_TickTime(prescaller_type prescaler);

#endif /* MCAL_TIMER0_TIMER_INTERFACE_H_ */

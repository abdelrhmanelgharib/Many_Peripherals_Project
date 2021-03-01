/*
 * DC.c
 *
 *  Created on: Feb 23, 2021
 *  Author: Kariman
 *  Team: GEEKs
 */

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIMER0/TIMER0_Interface.h"
#include "DC_config.h"
#include "DC_interface.h"


u8 DC_GenVar_Detect_direction ;

void DC_voidInitialize(void)
{
	//configure PB1,PB2(Motor pins) as output pins
	DIO_void_setPin_direction(DC_PORT, DC_POSITIVE_PIN,OUTPUT);
	DIO_void_setPin_direction(DC_PORT, DC_NEGATIVE_PIN,OUTPUT);
}

/******************************************************************************
 * function to rotate the motor according to the required direction sent to it*
 ******************************************************************************/
void DC_voidRotate(dc_direction direction)
{
	if(direction == CLK_WISE)
	{
		//we using pwm so first pin is fixed to pin oc0 we can't control it here
		//Rotate clock wise
	//	DIO_void_setPin_value(DC_PORT, DC_POSITIVE_PIN, HIGH);
		DIO_void_setPin_value(DC_PORT, DC_NEGATIVE_PIN, LOW);
		DC_GenVar_Detect_direction = CLK_WISE ;
	}//end if
	else if(direction == ANTI_CLK_WISE)
	{
		//Rotate anti-clock wise
	//	DIO_void_setPin_value(DC_PORT, DC_POSITIVE_PIN, LOW);
		DIO_void_setPin_value(DC_PORT, DC_NEGATIVE_PIN, HIGH);
		DC_GenVar_Detect_direction = ANTI_CLK_WISE ;
	}//end else if
	else
	{
		//do nothing
	}//end else
}//end DC_voidRotate

/*********************************************************************
 * function to set the motor speed according to duty cycle sent to it*
 *********************************************************************/
void DC_voidSetSpeed(u8 Copy_DutyCycle)
{
	//initialize the timer to work on PWM mode

	TIMER0_void_Intialize(TIMER0_PHASECORRECT_MODE,Prescaller_1024,TIMER0_NONINVERTING_PWM_OC0);
	// initialise phase correct& prescaller 1024 , non inverting mode
	if (DC_GenVar_Detect_direction == CLK_WISE)
	{
		TIMER0_void_PhaseCorrectPWM(Copy_DutyCycle,TIMER0_NONINVERTING_PWM_OC0);
	// set the running time so we need the other connect to set to low so that it can work
	}
	else if (DC_GenVar_Detect_direction == ANTI_CLK_WISE)
	{
		TIMER0_void_PhaseCorrectPWM(100 - Copy_DutyCycle,TIMER0_NONINVERTING_PWM_OC0);
	// set the running time so we need the other connect to set to HIGH so that it can work
	}

}//end DC_voidSpeed

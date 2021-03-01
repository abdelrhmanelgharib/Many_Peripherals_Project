/*
 * DC_interface.h
 *
 *  Created on: Feb 23, 2021
 *  Author: Kariman
 *  Team: GEEKs
 */

#ifndef HAL_DC_MOTOR_DC_INTERFACE_H_
#define HAL_DC_MOTOR_DC_INTERFACE_H_

typedef enum
{
	CLK_WISE = 0,
	ANTI_CLK_WISE
}dc_direction;

void DC_voidInitialize(void);

/******************************************************************************
 * function to rotate the motor according to the required direction sent to it*
 * choose from: -CLK_WISE													  *
 * 				-ANTI_CLK_WISE												  *
 ******************************************************************************/
void DC_voidRotate(dc_direction direction);


/*********************************************************************
 * function to set the motor speed according to duty cycle sent to it*
 * choose from: 0 to 255											 *
 *********************************************************************/
void DC_voidSetSpeed(u8 Copy_DutyCycle);

#endif /* HAL_DC_MOTOR_DC_INTERFACE_H_ */

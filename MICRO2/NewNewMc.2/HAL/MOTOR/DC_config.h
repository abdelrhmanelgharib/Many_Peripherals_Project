/*
 * DC_config.h
 *
 *  Created on: Feb 23, 2021
 *  Author: Kariman
 *  Team: GEEKs
 */

#ifndef HAL_DC_MOTOR_DC_CONFIG_H_
#define HAL_DC_MOTOR_DC_CONFIG_H_

/**********************************************************************
 * Macros to configure the 2 pins for motor wires to be connected with*
 **********************************************************************/
#define DC_POSITIVE_PIN		PIN3
#define DC_NEGATIVE_PIN		PIN2

/*********************************************************************
 * Macro to configure the PORT on which the motor wires are connected*
 *********************************************************************/
#define DC_PORT				PORTB_ID

#endif /* HAL_DC_MOTOR_DC_CONFIG_H_ */

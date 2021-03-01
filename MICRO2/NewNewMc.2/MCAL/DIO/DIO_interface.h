/*
 * DIO_interface.h
 *
 *  Created on: Feb 17, 2021
 *  Author: Kariman
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/bit_math.h"
#include "../../MCAL/DIO/Memmap.h"

typedef enum
{
	PORTA_ID = 0,
	PORTB_ID,
	PORTC_ID,
	PORTD_ID
}port_type;

typedef enum
{
	PIN0 = 0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}pin_type;

typedef enum
{
	INPUT = 0,
	OUTPUT
}direction_type;

typedef enum
{
	LOW = 0,
	HIGH
}value_type;

//void DIO_void_init(void);
void DIO_void_setPin_value(port_type port, pin_type pin,value_type value);
void DIO_void_setPin_direction(port_type port, pin_type pin,direction_type direction);
value_type DIO_value_type_getPin_value(port_type port, pin_type pin);
void DIO_void_setPort_direction(port_type port, u8 direction);
void DIO_void_setPort_value(port_type port, u8 value);

#endif /* MCAL_DIO_DIO_INTERFACE_H_ */

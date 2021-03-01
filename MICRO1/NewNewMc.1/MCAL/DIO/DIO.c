/*
 * DIO.c
 *
 *  Created on: Feb 17, 2021
 *  Author: Kariman
 */

#include "Memmap.h"
#include "DIO_interface.h"

#include "../../LIB/STD_TYPES.h"

void DIO_void_setPin_value(port_type port, pin_type pin,value_type value)
{
	if(value == LOW)
	{
		switch(port)
		{
		case PORTA_ID:
			CLRBIT(PORTA, pin);
			break;
		case PORTB_ID:
			CLRBIT(PORTB, pin);
			break;
		case PORTC_ID:
			CLRBIT(PORTC, pin);
			break;
		case PORTD_ID:
			CLRBIT(PORTD, pin);
			break;
		}//end switch
	}//end if
	else if(value == HIGH)
	{
		switch(port)
		{
		case PORTA_ID:
			SETBIT(PORTA, pin);
			break;
		case PORTB_ID:
			SETBIT(PORTB, pin);
			break;
		case PORTC_ID:
			SETBIT(PORTC, pin);
			break;
		case PORTD_ID:
			SETBIT(PORTD, pin);
			break;
		}//end switch
	}//end else if
	else
	{

	}//end else
}//end DIO_void_setPin_value
void DIO_void_setPin_direction(port_type port, pin_type pin,direction_type direction)
{
	if(direction == INPUT)
	{
		switch(port)
		{
		case PORTA_ID:
			CLRBIT(DDRA, pin);
			break;
		case PORTB_ID:
			CLRBIT(DDRB, pin);
			break;
		case PORTC_ID:
			CLRBIT(DDRC, pin);
			break;
		case PORTD_ID:
			CLRBIT(DDRD, pin);
			break;
		}//end switch
	}//end if
	else if(direction == OUTPUT)
	{
		switch(port)
		{
		case PORTA_ID:
			SETBIT(DDRA, pin);
			break;
		case PORTB_ID:
			SETBIT(DDRB, pin);
			break;
		case PORTC_ID:
			SETBIT(DDRC, pin);
			break;
		case PORTD_ID:
			SETBIT(DDRD, pin);
			break;
		}//end switch
	}//end else if
	else
	{

	}//end else
}//end DIO_void_setPin_direction
value_type DIO_value_type_getPin_value(port_type port, pin_type pin)
{
	value_type ret_val;

	switch(port)
	{
	case PORTA_ID:
		ret_val = GETBIT(PINA, pin);
		break;
	case PORTB_ID:
		ret_val = GETBIT(PINB, pin);
		break;
	case PORTC_ID:
		ret_val = GETBIT(PINC, pin);
		break;
	case PORTD_ID:
		ret_val = GETBIT(PIND, pin);
		break;
	}//end switch

	return ret_val;
}//end DIO_value_type_getPin_value
void DIO_void_setPort_direction(port_type port, u8 direction)
{
	switch(port)
	{
	case PORTA_ID:
		DDRA = direction;
		break;
	case PORTB_ID:
		DDRB = direction;
		break;
	case PORTC_ID:
		DDRC = direction;
		break;
	case PORTD_ID:
		DDRD = direction;
		break;
	}//end switch

}//end DIO_void_setPort_direction
void DIO_void_setPort_value(port_type port, u8 value)
{
	switch(port)
	{
	case PORTA_ID:
		PORTA = value;
		break;
	case PORTB_ID:
		PORTB = value;
		break;
	case PORTC_ID:
		PORTC = value;
		break;
	case PORTD_ID:
		PORTD = value;
		break;
	}//end switch
}//end DIO_void_setPort_value

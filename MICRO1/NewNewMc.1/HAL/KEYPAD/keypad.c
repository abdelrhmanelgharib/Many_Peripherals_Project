/*
 * keypad.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nada
 */




#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "keypad_Config.h"
#include "keypad_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "util/delay.h"


void KeyPad_void_intialize(void)
{
/*	//keypad connected to portD
	//rows connected to pins 0/1/2/3
	//columns connected to pins 4/5/6/78/*/
}

static u8 KeyPad_4x4_adjustKeyNumber(u8 button_number)
{
	switch(button_number)
	{
		case 1: return 7;
				break;
		case 2: return 8;
				break;
		case 3: return 9;
				break;
		case 4: return '%'; // ASCII Code of %
				break;
		case 5: return 4;
				break;
		case 6: return 5;
				break;
		case 7: return 6;
				break;
		case 8: return '*'; /* ASCII Code of '*' */
				break;
		case 9: return 1;
				break;
		case 10: return 2;
				break;
		case 11: return 3;
				break;
		case 12: return '-'; /* ASCII Code of '-' */
				break;
		case 13: return ' ';  /* ASCII of Space */
				break;
		case 14: return 0;
				break;
		case 15: return '='; /* ASCII Code of '=' */
				break;
		case 16: return '+'; /* ASCII Code of '+' */
				break;
		default: return button_number;
	}
}
u8 KeyPad_getPressedKey(void)
{
		u8 col,row;
		while(1)
		{
		for(col=0;col<N_col;col++) /* loop for columns */
		{
		/*
		 * each time only one of the column pins will be output and
		 * the rest will be input pins include the row pins DDRD= (0b00010000<<col);
		 */

		DIO_void_setPort_direction(KEYPAD_PORT, (0b00010000<<col));

		/*
		 * clear the output pin column in this trace and enable the internal
		 * pull up resistors for the rows pins PORTD = (~(0b00010000<<col));
		 */
		DIO_void_setPort_value(KEYPAD_PORT, (~(0b00010000<<col)));

			for(row=0;row<N_row;row++) /* loop for rows */
				{
				if (DIO_value_type_getPin_value(KEYPAD_PORT, row) == LOW) /* if the switch is press in this row */
				{return KeyPad_4x4_adjustKeyNumber((row*N_col)+col+1);}//end if
				}//end for loop (rows)
			}//end for columns loop
		}//end while(1)
	}//end function




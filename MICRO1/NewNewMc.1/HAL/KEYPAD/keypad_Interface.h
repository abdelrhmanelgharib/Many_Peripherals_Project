/*
 * keypad_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nada
 */

#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#define N_col 4
#define N_row 4


void KeyPad_void_intialize(void);
u8 KeyPad_getPressedKey(void);

#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */

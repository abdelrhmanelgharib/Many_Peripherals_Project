/*
 * UART_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nada
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

void UART_void_initialize(void);
void UART_void_send_data(u8 data);
u8 UART_void_recieve_data(void);
u8 UART_u8RecieveDataNoBLOCKING(u8* ptr_data);
#endif /* MCAL_UART_UART_INTERFACE_H_ */

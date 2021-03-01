/*
 * SERV_UART.h
 *
 *  Created on: Feb 22, 2021
 *      Author: medox
 */

#ifndef SERV_SERV_UART_SERV_UART_H_
#define SERV_SERV_UART_SERV_UART_H_

#include "../LIB/STD_TYPES.h"

void SER_UART_void_send_string(u8* s);
void SER_UART_void_receive_string(u8* s);
void SER_UART_void_receive_string_NOBLOCKING(u8* s);

#endif /* SERV_SERV_UART_SERV_UART_H_ */

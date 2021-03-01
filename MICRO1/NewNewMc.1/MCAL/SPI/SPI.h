/*
 * SPI.h
 *
 *  Created on: Jan 14, 2018
 *      Author: Mohamed
 */

#ifndef SPI_H_
#define SPI_H_

#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_TYPES.h"

void SPI_ReceiveString(u8 *str);
void SPI_SendString(u8 *str);
u8 SPI_ReceiveByte();
void SPI_SendByte(u8 data);
void SPI_InitSlave();
void SPI_InitMaster();


#endif /* SPI_H_ */

/*
 * SPI.c
 *
 *  Created on: Jan 14, 2018
 *      Author: Mohamed
 */

#include "SPI.h"
#include "../DIO/Memmap.h"
#include "../../LIB/STD_TYPES.h"
#include "../DIO/DIO_interface.h"
void SPI_InitMaster()
{
	DIO_void_setPin_direction(PORTB_ID,PIN4,OUTPUT);
	DIO_void_setPin_direction(PORTB_ID,PIN5,OUTPUT);
	DIO_void_setPin_direction(PORTB_ID,PIN6,INPUT);
	DIO_void_setPin_direction(PORTB_ID,PIN7,OUTPUT);
	DIO_void_setPin_value(PORTB_ID,PIN4,LOW);
	SPCR |= (1<<SPE)|(1<<MSTR);
}

void SPI_InitSlave()
{
	DIO_void_setPin_direction(PORTB_ID,PIN6,OUTPUT);
	SPCR |= (1<<SPE);
}

void SPI_SendByte(u8 data)
{
	SPDR = data;
	while(Bit_Is_Clear(SPSR,SPIF));
}

u8 SPI_ReceiveByte()
{
	while(Bit_Is_Clear(SPSR,SPIF));
	return SPDR;
}

void SPI_SendString(u8 *str)
{
	while(*str)
	{
		SPI_SendByte(*str);
		str++;
	}
}

void SPI_ReceiveString(u8 *str)
{
	u8 i = 0;
	str[i] = SPI_ReceiveByte();
	while(str[i] != '#')
	{
		i++;
		str[i] = SPI_ReceiveByte();
	}
	str[i] = '\0';
}

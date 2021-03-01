#include "SERV_UART.h"
#include "../MCAL/UART/UART_interface.h"
#include "../SERV_UART/SERV_UART.h"
#include "../MCAL/DIO/Memmap.h"
#include "../LIB/BIT_Math.h"
void SER_UART_void_send_string(u8* s)
{
	u8 count=0;
	while (s[count]!='\0')
	{
		UART_void_send_data(s[count]);
		count++;
	}
}
void SER_UART_void_receive_string(u8* s)
{
	u8 count=0;
	s[count]=UART_void_recieve_data();
	while(s[count]!='$')
	{
		count++;
		s[count]=UART_void_recieve_data();
	}
	s[count]='\0';
}
void SER_UART_void_receive_string_NOBLOCKING(u8* s)
{
	       u8 statue,data,count=0;
	do{
		    statue=UART_u8RecieveDataNoBLOCKING(& data);
		    if (statue)
				{
					s[count]=data;
					count++;
				}
		    else
				{
					break;
				}
	     }while(s[count-1]!='$');
	s[count-1]='\0';
}

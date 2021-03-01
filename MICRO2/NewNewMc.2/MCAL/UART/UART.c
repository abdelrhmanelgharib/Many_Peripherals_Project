#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/Memmap.h"
#include "../../LIB/BIT_MATH.h"
/*
#include "../../MCAL/DIO/Memmap.h"
#include "ADC_Interface.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_type.h"
*/
void UART_void_initialize(void)
{
	SETBIT(UCSRB,RXEN);
	SETBIT(UCSRB,TXEN);
	CLRBIT(UCSRC, UMSEL);
	CLRBIT(UCSRC, UPM0);
	CLRBIT(UCSRC, UPM1);
	CLRBIT(UCSRC, USBS);
	SETBIT(UCSRC, UCSZ0);
	SETBIT(UCSRC, UCSZ1);
	CLRBIT(UCSRB, UCSZ2);

	//BAUD RATE
	UBRRH=0;
	UBRRL=207;

}


void UART_void_send_data(u8 data)
{
	while (!(GETBIT(UCSRA,UDRE)));
	UDR=data;
}

u8 UART_void_recieve_data(void)
{
	while(!(GETBIT(UCSRA,RXC)));
	return UDR;
}
u8 UART_u8RecieveDataNoBLOCKING(u8* ptr_data)
{
    u8 status = 0;
    if (GETBIT(UCSRA, RXC))
    {
        *ptr_data =UDR;
        status =1;
    }
    else
    {
        //
    }
    return status;
}

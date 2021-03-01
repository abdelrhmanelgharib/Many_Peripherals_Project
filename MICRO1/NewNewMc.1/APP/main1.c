#include "avr/delay.h"
#include "stdlib.h"

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_Math.h"
#include "../HAL/KEYPAD/keypad_Interface.h"
#include "../MCAL/DIO/DIO_Interface.h"

#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../MCAL/UART/UART_interface.h"
#include "../SERV_UART/SERV_UART.h"
#include "../HAL/sensors/sensors.h"
#include "../MCAL/DIO/Memmap.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../HAL/Ultrasonic/Ultrasonic_int.h"
#include "../MCAL/SPI/SPI.h"
#include "../HAL/Ultrasonic/Ultrasonic_int.h"


int main(void)
{
	u16 Ultra_data;
	u16 Temp_data;
	u8 Buffer[2];
	u8 key_num;
	u8 Buffer1[2];


	///////////////////////////
	/* set direction of temperature sensor */
	DIO_void_setPin_direction(PORTA_ID,PIN0,INPUT);
	DIO_void_setPin_direction(PORTD_ID,PIN1,OUTPUT);

	/* initialize ADC   */
	ADC_void_init(ADC_PRESCALLER_64,ADC_AREFF);
	UART_void_initialize();

	KeyPad_void_intialize();

	ULTRASONIC_voidInit();


	/* Read password form user then send to MCU2 to check  */
	do
	{
		key_num = KeyPad_getPressedKey();
		if((key_num >= 0) && (key_num <= 9))
			 {
				 UART_void_send_data(key_num+'0');
			 }
			/* new pressed every 300ms */
			 _delay_ms(300);
	}while(key_num!='=');


	while(1)
	{
		/* send temperature to MCU2 */
		 UART_void_send_data('T');
		 /* store temperature degree in TempData */
		 Temp_data=TEMP_u16_Read();
		 itoa(Temp_data,Buffer,10);
		 SER_UART_void_send_string(Buffer);

		 /* send distance to MCU2 */
//		 UART_void_send_data('U');
//		 ULTRASONIC_voidRead();
//		 Ultra_data=getdistance();
//		 itoa(Ultra_data,Buffer1,10);
//		 SER_UART_void_send_string(Buffer1);
	}

}


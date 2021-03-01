#include "includes.h"

int main(void)
{        ////////////////////////////////
	DIO_void_setPin_direction(PORTD_ID,PIN0,INPUT);
	DIO_void_setPin_direction(PORTD_ID,PIN1,OUTPUT);
	LCD_void_init(LCD_enum_4BITS_MODE);
	UART_void_initialize();
	TIMER0_void_Intialize(TIMER0_FASTPWM_MODE , Prescaller_64 , TIMER0_NONINVERTING_PWM_OC0 );;
	 ////////////////////////////////
	u8 StorePass[]="123456";
	u32 i, j,count=0,number=sizeof(StorePass)-1;
	char pass[sizeof(StorePass)-1];
	u32 digit=0;
	//////////////////////////////
	LCD_void_goto(0,1);
	LCD_void_write_string("ENTER PASSWORD");
	LCD_void_goto(1,1);
	for(i=0;i<=sizeof(StorePass)-1;i++)
	{
				pass[i] = UART_void_recieve_data();      //Receive PASSWARD
				LCD_void_write_char(pass[i]);
	}
	for(j=0;j<number;j++)
		  {
			if(pass[j]==StorePass[j])
			count++;
		  }
	  if(count==number)
	  {
		  LCD_void_send_command(0x01);

		while(1)
		{
			/////////////////////////////////////////////////////////////////
///////////////////////////////////START TEMP SENSOR/////////////////////////////////////
			////////////////////////////////////////////////////////////////
			 u8 check_T=UART_void_recieve_data();
			 if(check_T=='T')
			 {
				  u8 Temp_Data[2]={0};
				  LCD_void_goto(0,0);
				  LCD_void_write_string((u8*)"Temp = ");
				  for(i=0;i<2;i++)
				  {
					  Temp_Data[i] = UART_void_recieve_data();      //Receive PASSWARD
					  LCD_void_write_char(Temp_Data[i]);
				  }
				  LCD_void_write_string('C');
				  u32 digit=0;
				  digit = atoi(Temp_Data);
				  if(digit>=10)
				  {
					  LED_void_LED_Direction(PORTC_ID, PIN0);
					  LED_void_LEDINT(10);
				  }
				  else if (digit>=20)
				  {
					  LED_void_LED_Direction(PORTC_ID, PIN0);
					  LED_void_LEDINT(30);
				  }
	  }//end  if
//////////////////////////////////////	END TEMP SENSOR////////////////////////////////////
                                         /////////////////////////////////////////////////
 /////////////////////////////////////START ULTRA SENSOR///////////////////////////////////
//                                         /////////////////////////////////////////////////
//				u8 check_U=UART_void_recieve_data();
//				if(check_U=='U')
//				{
//					u8 Ultra_Data[2]={0};
//					  LCD_void_goto(1,0);
//					  LCD_void_write_string((u8*)"Dis = ");
//					  for(i=0;i<2;i++)
//					  {
//						  Ultra_Data[i]= UART_void_recieve_data();     //Receive data
//						  LCD_void_write_string(Ultra_Data);
//					  }
//
//
//					 LCD_void_write_string((u8*)"Cm");
//
//					  digit = atoi(Ultra_Data);
//					  if(digit>=30)
//					  {
//						  DC_voidSetSpeed(20);
//					  }
//					  else if (digit>=50)
//					  {
//						  DC_voidSetSpeed(50);
//					  }
//				}


///////////////////////////////END ULTRA DATA///////////////////////////////////////////

		}//END WHILE

		  }
		  else
		  {
			  LCD_void_send_command(0x01);
			  LCD_void_goto(0,1);
			  LCD_void_write_string((u8*)"Wrong Password");
			  _delay_ms(2000);
			  LCD_void_send_command(0x01);
			  LCD_void_goto(0,1);
			  LCD_void_write_string((u8*)"ENTER PASSWORD");

		  }
}

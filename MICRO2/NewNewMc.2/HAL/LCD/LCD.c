#include "LCD_Interface.h"
#include "LCD_config.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../LIB/BIT_Math.h"
#include <avr/delay.h>

void LCD_void_init(lcd_mode mode)
{
	DIO_void_setPin_direction(PORTA_ID, LCD_RS_PIN , OUTPUT);
	DIO_void_setPin_direction(PORTA_ID, LCD_E_PIN , OUTPUT);
if(mode == LCD_enum_8BITS_MODE)
	{
		// port pins direction = output
		DIO_void_setPort_direction(LCD_8BITS_DATA_PORT,0xff);
		//lcd init commands

		_delay_ms(30);
		LCD_void_send_command(0x38);
		_delay_ms(1);
		LCD_void_send_command(0x0E);
		_delay_ms(1);
		LCD_void_send_command(0x01);
		_delay_ms(3);
	}
else if(mode == LCD_enum_4BITS_MODE)
	{
		DIO_void_setPin_direction(LCD_4BITS_PORT , LCD_4BITS_PIN1 , OUTPUT);
		DIO_void_setPin_direction(LCD_4BITS_PORT , LCD_4BITS_PIN2 , OUTPUT);
		DIO_void_setPin_direction(LCD_4BITS_PORT , LCD_4BITS_PIN3 , OUTPUT);
		DIO_void_setPin_direction(LCD_4BITS_PORT , LCD_4BITS_PIN4 , OUTPUT);

		_delay_ms(35);
		LCD_void_send_command(0x02);
		_delay_ms(1);
		LCD_void_send_command(0x28);
		_delay_ms(1);
		LCD_void_send_command(0x0E);
		_delay_ms(1);
		LCD_void_send_command(0x01);
		_delay_ms(1);
		LCD_void_send_command(0x06);
		_delay_ms(3);
	}

}
void LCD_void_send_command(u8 command)
{
	_delay_ms(5);
	DIO_void_setPin_value(PORTA_ID , LCD_RS_PIN ,LOW);

#if LCD_CURRENT_MODE == LCD_8BITS_MODE

	DIO_void_setPort_value(LCD_8BITS_DATA_PORT , command);

	DIO_void_setPort_value(PORTA_ID , LCD_E_PIN , HIGH);
	_delay_ms(1);
	DIO_void_setPort_value(PORTA_ID , LCD_E_PIN , LOW);

#elif LCD_CURRENT_MODE == LCD_4BITS_MODE

//	DIO_void_setPin_value(LCD_4BITS_PORT , LCD_4BITS_PIN1 , GETBIT(command,4));
//	DIO_void_setPin_value(LCD_4BITS_PORT , LCD_4BITS_PIN2 , GETBIT(command,5));
//	DIO_void_setPin_value(LCD_4BITS_PORT , LCD_4BITS_PIN3 , GETBIT(command,6));
//	DIO_void_setPin_value(LCD_4BITS_PORT , LCD_4BITS_PIN4 , GETBIT(command,7));
	 u8 porta_val = ((PORTA & 0x87) | ((command &0xf0) >> 1));
	 DIO_void_setPort_value(LCD_4BITS_PORT , porta_val);
	 DIO_void_setPin_value(PORTA_ID , LCD_E_PIN , HIGH);
	 _delay_ms(1);
	 DIO_void_setPin_value(PORTA_ID , LCD_E_PIN , LOW);
	 _delay_ms(1);
//	DIO_void_setPin_value(LCD_4BITS_PORT , LCD_4BITS_PIN1 , GETBIT(command,0));
//	DIO_void_setPin_value(LCD_4BITS_PORT , LCD_4BITS_PIN2 , GETBIT(command,1));
//	DIO_void_setPin_value(LCD_4BITS_PORT , LCD_4BITS_PIN3 , GETBIT(command,2));
//	DIO_void_setPin_value(LCD_4BITS_PORT , LCD_4BITS_PIN4 , GETBIT(command,3));
	 porta_val = ((PORTA & 0x87)|(command << 3));
	 DIO_void_setPort_value(LCD_4BITS_PORT , porta_val );
	 DIO_void_setPin_value(PORTA_ID , LCD_E_PIN , HIGH);
	_delay_ms(1);
	DIO_void_setPin_value(PORTA_ID , LCD_E_PIN , LOW);


#endif
}
void LCD_void_write_char(u8 ch)
{
	_delay_ms(5);
	DIO_void_setPin_value(PORTA_ID , LCD_RS_PIN ,HIGH);

#if LCD_CURRENT_MODE == LCD_8BITS_MODE

	DIO_void_setPort_value(LCD_8BITS_DATA_PORT , ch);

	DIO_void_setPin_value(PORTA_ID , LCD_E_PIN , HIGH);
	_delay_ms(1);
	DIO_void_setPin_value(PORTA_ID , LCD_E_PIN , LOW);

#elif LCD_CURRENT_MODE == LCD_4BITS_MODE
//	DIO_void_setPin_value(LCD_4BITS_PORT , LCD_4BITS_PIN1 , GETBIT(ch,4));
//	DIO_void_setPin_value(LCD_4BITS_PORT , LCD_4BITS_PIN2 , GETBIT(ch,5));
//	DIO_void_setPin_value(LCD_4BITS_PORT , LCD_4BITS_PIN3 , GETBIT(ch,6));
//	DIO_void_setPin_value(LCD_4BITS_PORT , LCD_4BITS_PIN4 , GETBIT(ch,7));
	 u8 porta_val = ((PORTA & 0x87) | ((ch &0xf0) >> 1));
	 DIO_void_setPort_value(LCD_4BITS_PORT , porta_val);
	 DIO_void_setPin_value(PORTA_ID , LCD_E_PIN , HIGH);
	 _delay_ms(1);
	 DIO_void_setPin_value(PORTA_ID , LCD_E_PIN , LOW);

//	DIO_void_setPin_value(LCD_4BITS_PORT , LCD_4BITS_PIN1 , GETBIT(ch,0));
//	DIO_void_setPin_value(LCD_4BITS_PORT , LCD_4BITS_PIN2 , GETBIT(ch,1));
//	DIO_void_setPin_value(LCD_4BITS_PORT , LCD_4BITS_PIN3 , GETBIT(ch,2));
//	DIO_void_setPin_value(LCD_4BITS_PORT , LCD_4BITS_PIN4 , GETBIT(ch,3));
	 porta_val = ((PORTA & 0x87)|(ch << 3));
	 DIO_void_setPort_value(LCD_4BITS_PORT , porta_val);
	 DIO_void_setPin_value(PORTA_ID , LCD_E_PIN , HIGH);
	_delay_ms(1);
	DIO_void_setPin_value(PORTA_ID , LCD_E_PIN , LOW);


#endif
}
void LCD_void_write_string(u8* str)
{
	   u8 counter=0;
       while(str[counter]!='\0')
       {
    	   LCD_void_write_char(str[counter]);
    	   counter++;
       }
}
void LCD_void_print_unsigned_integer(u32 number)
{
	   u8 Str[16];
		       u8 count=0;
		       if(number==0)
		       {
		    	   LCD_void_write_char('0');
		       }
		       while(number && (count<16))
		       {
		    	   Str[count++]=number%10;
		    	   number/=10;
		       }
		       while(count)
		       {
		    	   LCD_void_write_char(Str[--count]+'0');
		       }
}
void LCD_void_print_signed_integer  (s32 number)
{
	               s8 Str[16];
			       u8 count=0;
			       if(number==0)
					   {
						   LCD_void_write_char('0');
					   }
			       while(number <0)
					   {
			    	   LCD_void_write_char('-');
						   number*=-1;
					   }
				  while(number && (count<16))
					   {
						   Str[count++]=number%10;
						   number/=10;
					   }

				   while(count)
					   {
						   LCD_void_write_char(Str[--count]+'0');
					   }
}
void LCD_void_goto(u8 raw , u8 col)
{
         switch(raw)
         {
         case 0:
        	 if ((col <16) &&  (col >=0))
        	 {
        		 LCD_void_send_command(0x80+col);
        	 }
        	 break;
         case 1:
			 if ((col <16) &&  (col >=0))
			 {
				 LCD_void_send_command(0xc0+col);
			 }
			 break;
         }
}

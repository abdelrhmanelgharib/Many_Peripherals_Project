#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"


typedef enum {
	LCD_enum_4BITS_MODE = 0 ,
	LCD_enum_8BITS_MODE
}lcd_mode;

void LCD_void_init(lcd_mode mode);
void LCD_void_send_command(u8 command);
void LCD_void_write_char(u8 ch);
void LCD_void_write_string(u8* str);
void LCD_void_print_unsigned_integer(u32 number);
void LCD_void_print_signed_integer  (s32 number);
void LCD_void_goto(u8 raw , u8 col);


#endif /* HAL_LCD_LCD_INTERFACE_H_ */

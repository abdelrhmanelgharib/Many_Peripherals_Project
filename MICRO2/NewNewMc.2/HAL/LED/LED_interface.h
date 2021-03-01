

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_


// typedef enum
// {
//     LED0 = 0 ,
//     LED1 ,
//     LED2 ,
//     LED3 
// }led_num;
#include "../../LIB/STD_TYPES.h"
typedef enum
{
    FORWARD = 0 ,
    REVERSE
}led_connection;


void LED_void_LED_Direction(port_type LED_Port, pin_type LED_Pin);

void LED_void_LEDOn(port_type LED_Port, pin_type LED_Pin, led_connection con);
void LED_void_LEDOff(port_type LED_Port, pin_type LED_Pin, led_connection con);
void LED_void_LEDToggle(port_type LED_Port, pin_type LED_Pin);
void LED_void_LEDINT(u8 Duty_Cycle);

#endif  /* LED_INTERFACE_H_ */

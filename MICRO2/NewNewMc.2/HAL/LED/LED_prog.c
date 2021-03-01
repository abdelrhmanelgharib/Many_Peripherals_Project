

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIMER0/TIMER0_Interface.h"
#include "LED_interface.h"



void LED_void_LED_Direction(port_type LED_Port, pin_type LED_Pin)
{
	DIO_void_setPin_direction(LED_Port, LED_Pin, OUTPUT);
}


void LED_void_LEDOn(port_type LED_Port, pin_type LED_Pin, led_connection con)
{
    if (con == FORWARD)
    {
        DIO_void_setPin_value(LED_Port, LED_Pin, HIGH);
    }
    else
    {
        DIO_void_setPin_value(LED_Port, LED_Pin, LOW);   
    }
    
}

void LED_void_LEDOff(port_type LED_Port, pin_type LED_Pin, led_connection con)
{
    if (con == FORWARD)
    {
        DIO_void_setPin_value(LED_Port, LED_Pin, LOW);
    }
    else
    {
        DIO_void_setPin_value(LED_Port, LED_Pin, HIGH);   
    }
}

void LED_void_LEDToggle(port_type LED_Port, pin_type LED_Pin)
{
    
   // DIO_void_TogPin(LED_Port, LED_Pin);
}
void LED_void_LEDINT(u8 Duty_Cycle)
{
	TIMER0_void_FastPWM( Duty_Cycle , TIMER0_INVERTING_PWM_OC0, Prescaller_8);
}

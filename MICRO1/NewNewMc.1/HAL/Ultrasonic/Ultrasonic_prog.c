/**
 *  TEAM: GEEKS
 *  Final Project
 * 
*/
#include "util/delay.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"

#include "../../MCAL/TIMER0/TIMER0_Interface.h"
#include "../../MCAL/TIMER1/TIMER1_interface.h"
#include "../../MCAL/External_interrupt/ex_int.h"

#include "Ultrasonic_int.h"

#include "avr/interrupt.h"
#include "../../MCAL/DIO/Memmap.h"




static volatile u16 pulse = 0;
static volatile u8 i = 0;

void ULTRASONIC_voidInit(void)
{
    /* set direction of trriger and echo */
    DIO_void_setPin_direction(TRRIGER_PORT, TRRIGER_PIN, TRRIGER_DDR);
    DIO_void_setPin_direction(ECHO_PORT, ECHO_PIN, ECHO_DDR);
    // /* set value to echo */
    // DIO_void_setPin_value(ECHO_PORT, ECHO_PIN, ECHO_DDR);
    EXTI_void_int(INT0);
    EXTI_void_changeMod(EXT_CHANGE_MODE, INT0);
    TCCR1A = 0;
}


void ULTRASONIC_voidRead(void)
{
    /* enable trriger for 10 us to send brust single, then disable */
    DIO_void_setPin_value(TRRIGER_PORT, TRRIGER_PIN, HIGH);
    _delay_us(15);
    DIO_void_setPin_value(TRRIGER_PORT, TRRIGER_PIN, LOW);
}

ISR(INT0_vect)
{
    if (i==1)
    {
    	//stop timer
    	TIMER1_void_TimerStop();
    	pulse = TIMER1_u16CurrentTimerValue();
    	TIMER1_voidCLRCounter();
        i=0;
    }
    if (i==0)
    {
    	//no prescaller
    	TIMER1_void_TimerStart(NO_Prescaller);
        i=1;
    }
}
u16 getdistance(void)
{
	//LCD_void_print_signed_integer(1);
	return pulse/464;
}


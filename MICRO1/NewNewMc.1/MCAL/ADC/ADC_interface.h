#ifndef MCAL_32_ADC_ADC_INTERFACE_H_
#define MCAL_32_ADC_ADC_INTERFACE_H_

#include"../../LIB/STD_TYPES.h"

typedef enum {
       ADC_PRESCALLER_2 =0,
	   ADC_PRESCALLER_4,
	   ADC_PRESCALLER_8,
	   ADC_PRESCALLER_16,
	   ADC_PRESCALLER_32,
	   ADC_PRESCALLER_64,
	   ADC_PRESCALLER_128,
}prescaller_no;

typedef enum{
	ADC_AREFF=0,
	ADC_AVCC,
	ADC_INTERNAL=3,
}vreff_type;

#define Free_Running_mode                          0
#define Analog_Comparator                            1
#define External_Interrupt_Request_0            2
#define Timer_Counter0_Compare_Match      3
#define Timer_Counter0_Overflow                  4
#define Timer_Counter1_Compare_Match_B  5
#define Timer_Counter1_Overflow                  6
#define Timer_Counter1_Capture_Event        7
void ADC_void_init(prescaller_no prescaller,vreff_type vreff);
u16  ADC_u16_read(u8 channel);
u16 Async_ADC_u16_read(u8 channel,u8 Trigger_Source );

#endif /* MCAL_32_ADC_ADC_INTERFACE_H_ */

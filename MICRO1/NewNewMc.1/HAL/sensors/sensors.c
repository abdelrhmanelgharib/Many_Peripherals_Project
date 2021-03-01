#include "sensors.h"
#include "../../LIB/STD_TYPES.h"

u16 TEMP_u16_Read(void)
{
	//ADC_void_init(ADC_PRESCALLER_64 ,ADC_AVCC);
	u16 adc_read = ADC_u16_read(ADC0);

	u16 volt = ((unsigned long)5000 * adc_read)/1024;
	u16 temp =  volt /10;

	return temp;
}

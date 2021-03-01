#ifndef MCAL_EXTERNAL_INTERRUPT_EX_INT_H_
#define MCAL_EXTERNAL_INTERRUPT_EX_INT_H_


typedef enum
{
	EXT_LOW_MODE =0,
	EXT_CHANGE_MODE,
	EXT_FAILLING_MODE,
	EXT_RAISING_MODE

}ext_mode_type;

void EXTI_void_int( u8 INT);
void EXTI_void_changeMod (ext_mode_type mode,u8 INT);










#endif

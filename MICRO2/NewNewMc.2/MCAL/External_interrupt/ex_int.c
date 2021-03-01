#include  "../../LIB/BIT_MATH.h"
#include  "../../LIB/STD_TYPES.h"
#include "../DIO/Memmap.h"
#include  "ex_int.h"


void EXTI_void_int( u8 INT)
{
	//INT0 is input ( done )
	//  Enable peripheral interrupt enable
		switch(INT)
		{
		case INT0:
			SETBIT(GICR,6);
			break;
		case INT1:
			SETBIT(GICR,7);
			break;
		case INT2:
			SETBIT(GICR,5);
			break;
		}
     //Enable GIE
	 SETBIT(SREG,7);
}
void EXTI_void_changeMod(ext_mode_type mode,u8 INT)
{
     if (INT==INT0)
        {
       	 switch(mode )
       	 {
         case EXT_LOW_MODE :
			  CLRBIT(MCUCR,0);
			  CLRBIT(MCUCR,1);
			  break;
         case EXT_RAISING_MODE :
			  SETBIT(MCUCR,0);
			  SETBIT(MCUCR,1);
			  break;
         case EXT_FAILLING_MODE :
			  CLRBIT(MCUCR,0);
			  SETBIT(MCUCR,1);
			  break;
         case EXT_CHANGE_MODE :
			  SETBIT(MCUCR,0);
			  CLRBIT(MCUCR,1);
			  break;
            }
        }
     else if (INT==INT1)
            {
           	 switch(mode )
           	 {
             case EXT_LOW_MODE :
				  CLRBIT(MCUCR,2);
				  CLRBIT(MCUCR,3);
				  break;
             case EXT_RAISING_MODE :
				  SETBIT(MCUCR,2);
				  SETBIT(MCUCR,3);
				  break;
             case EXT_FAILLING_MODE :
				  CLRBIT(MCUCR,2);
				  SETBIT(MCUCR,3);
				  break;
             case EXT_CHANGE_MODE :
				  SETBIT(MCUCR,2);
				  CLRBIT(MCUCR,3);
				  break;
                }
            }
     else if (INT==INT2)
            {
         /*  	 switch(mode)
				 {
						 case EXT_RAISING_MODE :
								  SETBIT(mcucsr,6);
								  break;
						 case EXT_FAILLING_MODE :
								  CLRBIT(mcucsr,6);
								  break;
					}*/
            }
}

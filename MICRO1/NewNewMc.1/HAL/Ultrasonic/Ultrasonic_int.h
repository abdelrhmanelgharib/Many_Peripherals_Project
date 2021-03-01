


#ifndef ULTRASONIC_INT_H_
#define ULTRASONIC_INT_H_


#define TRRIGER_PORT     PORTD_ID
#define TRRIGER_PIN      PIN4
#define TRRIGER_DDR      OUTPUT



#define ECHO_PORT         PORTD_ID
#define ECHO_PIN          PIN2
#define ECHO_DDR          INPUT



void ULTRASONIC_voidInit(void);
void ULTRASONIC_voidRead(void);
u16 getdistance(void);


#endif  /* ULTRASONIC_INT_H_ */ 

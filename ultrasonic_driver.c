#include <LPC21xx.H>
#include "can_header.h"
unsigned int ultrasonic_read(void)
{ unsigned int time,distance;
	IOSET0|=trig_pin;
	delay_us(10);
	IOCLR0|=trig_pin;	
	while(!(IOPIN0 & echo_pin));
	start_timer1();
	while(IOPIN0 & echo_pin);
	time=stop_timer1();
	distance=(0.0343*time)/2;
 return distance;
}
unsigned int ultrasonic_read1(void)
{ unsigned int time,distance;
	IOSET0|=trig_pin1;
	delay_us(10);
	IOCLR0|=trig_pin1;	
	while(!(IOPIN0 & echo_pin1));
	start_timer1();
	while(IOPIN0 & echo_pin1);
	time=stop_timer1();
	distance=(0.0343*time)/2;
	return distance;
}
void start_timer1(void)
{ T1PR=60-1;
 T1TC=T1PC=0;
 T1TCR=1; 
}
unsigned int stop_timer1(void)
{ T1TCR=0;
 return T1TC;
}



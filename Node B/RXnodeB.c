#include "can_header.h"
U32 id,rtr,dlc,byteA,byteB;
U32 a,b;
main()
{ PINSEL0=0;
 IODIR0|=trig_pin|trig_pin1;
 IODIR0&=~((echo_pin)|(echo_pin1));
 can2_init();
 IOCLR0|=trig_pin;
 IOCLR0|=trig_pin1;
 uart0_init(115200); 
  while(1)
 {
 uart0_tx_string("before\r\n");
  can2_rx(&id,&rtr,&dlc,&byteA,&byteB);
  uart0_tx_string("after\r\n");
  if(id==0x108)
  {
   if(rtr==1)
   { 	a=ultrasonic_read();
		b=ultrasonic_read1();
	can2_tx(0x108,0,8,a,b);
	uart0_tx_string("a=");
	uart0_tx_integer(a);
	uart0_tx_string("\r\nb=");
	uart0_tx_integer(b);
	uart0_tx_string("\r\n");
   } 
  }
 }
}

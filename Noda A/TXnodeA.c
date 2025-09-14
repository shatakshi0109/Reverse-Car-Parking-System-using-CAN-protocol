#include "can_header.h"
#define rev_switch ((IOPIN0>>14)&1)
U32 id,rtr,dlc,byteA,byteB;
int flag=0;
main()
{
 IODIR0&=~(1<<14);
 IODIR0|= buzzer;
 can2_init();
 IOCLR0|=buzzer;
  while(1)
 { while((rev_switch==0))
   { if((rev_switch==0)&&(flag==0))
	 {
	  while(rev_switch==0);
	  can2_tx(0x108,1,8,0x0,0x0);
	  can2_rx(&id,&rtr,&dlc,&byteA,&byteB);
	  while(rev_switch==1)
	  {
	  while(((byteA <=30)||(byteB <=30))&&(rev_switch==1))
		{   IOSET0|=buzzer;
			delay_ms(100);
			IOCLR0|=buzzer;
			delay_ms(100);
			can2_tx(0x108,1,8,0x0,0x0);
	        can2_rx(&id,&rtr,&dlc,&byteA,&byteB);
		}
	  while(((byteA >30)&&(byteB >30))&&(rev_switch==1))
		{   IOSET0|=buzzer;
			delay_ms(800);
			IOCLR0|=buzzer;
			delay_ms(800);
			can2_tx(0x108,1,8,0x0,0x0);
	        can2_rx(&id,&rtr,&dlc,&byteA,&byteB);
		}
	  if(rev_switch==0)
	  {	  flag=1;
	  	  break;
	  }
	 }
	 }
	 if((rev_switch==0)&&(flag==1))
	 {
	  while(rev_switch==0);
	  IOCLR0|=buzzer;
	  flag=0;
	  break;
	 }
   }
 }
}


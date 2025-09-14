#include "can_header.h"


void can2_init(void)
{
 PINSEL1|=0x00014000;
 VPBDIV=1;
 C2MOD=0X1;
 AFMR=0X2;
 C2BTR=0X001C001D;
 C2MOD=0X0;
}

void can2_tx(U32 id, U32 rtr ,U32 dlc , U32 byteA, U32 byteB)
{
 C2TID1=id;
 C2TFI1=dlc<<16;
 if(rtr==0)
 {
  C2TFI1&=~(1<<30);
  C2TDA1= byteA;
  C2TDB1= byteB;
 }
 else
  C2TFI1|=(1<<30);
  
  C2CMR=(1<<0)|(1<<5);
  while(((C2GSR>>3)&1)==0);
}

void can2_rx(U32 *id,U32 *rtr,U32 *dlc,U32 *byteA, U32 *byteB )
{
 while((C2GSR&1)==0);
 
  *id=C2RID;
  *rtr=(C2RFS>>30)&1;
  *dlc=(C2RFS>>16)&0x0F;
  if(*rtr==0)
  {
  *byteB=C2RDB;
   *byteA=C2RDA;
   
  }
  C2CMR=(1<<2);
}










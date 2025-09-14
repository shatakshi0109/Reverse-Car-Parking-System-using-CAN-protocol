#include <LPC21xx.H>
typedef unsigned int U32;
#define buzzer (1<<21)
void can2_init(void);
void can2_tx(U32 id, U32 rtr ,U32 dlc , U32 byteA, U32 byteB);
void can2_rx(U32 *id,U32 *rtr,U32 *dlc,U32 *byteA, U32 *byteB );
void delay_sec(unsigned int sec);
void delay_ms(unsigned int ms);
void uart0_init(unsigned int baud);
void uart0_tx(unsigned char data);
unsigned char uart0_rx(void);
void uart0_tx_string(char *p);
void uart0_dec_hex(unsigned char num);
void uart0_rx_string(unsigned char *ptr,int len);
void uart0_tx_integer(unsigned int n);
void uart0_tx_float(float f);
void delay_sec(unsigned int sec);
void delay_ms(unsigned int ms);
void delay_us(unsigned int us);







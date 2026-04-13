#include<lpc21xx.h>
#include "header.h"
#define LED 1<<4
int main()
{
	CAN2_DF rm1;
	IODIR0|=LED;
	IOSET0|=LED;
	can2_init();
	uart1_init(115200);

	uart1_tx_string("NodeB TESTING CAN\r\n");

	  while(1)
	  {		

		can2_rx(&rm1);

		if(rm1.rtr==0)
		{

			uart1_tx_string("NodeB: DATA-FRAME is received\r\n");

			uart1_tx_hex(rm1.id);

			uart1_tx(' ');

			uart1_tx_hex(rm1.dlc);

			uart1_tx(' ');

			uart1_tx_hex(rm1.byteA);

			uart1_tx(' ');

			uart1_tx_hex(rm1.byteB);

			uart1_tx_string("\r\n");

		}	

		else
		{

			uart1_tx_string("NodeB: REMOTE-FRAME is received\r\n");

			uart1_tx_hex(rm1.id);

			uart1_tx(' ');

			uart1_tx_hex(rm1.dlc);

			uart1_tx(' ');

			uart1_tx_string("\r\n");
		}
		if(rm1.byteA==1)
		{
			IOCLR0=LED;
			delay_sec(2);
			IOSET0=LED;
		}	

	}


	

}

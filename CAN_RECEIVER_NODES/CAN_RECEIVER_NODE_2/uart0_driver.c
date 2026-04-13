#include <LPC21xx.H>
#include<stdio.h>

#include "header.h"


void uart1_init(unsigned int baud)
{

	PINSEL0|=1<<16|1<<18;

	U1LCR=0x83;

	switch(baud){	

		case 115200:U1DLL=32;	break;//PCLK=60MHz

		case 921600:U1DLL=4;	break;

		default:	U1DLL=32	;	

	}

	U1LCR=0x03;

}


void uart1_tx(unsigned char data)
{

	U1THR=data;

	while((U1LSR&(1<<5))==0);

}


unsigned char uart1_rx(void)
{

	while((U1LSR&0x1)==0);

	return U1RBR;

}




void uart1_tx_string(char *ptr)
{

	while(*ptr!=0)
	{

		U1THR=*ptr;

		while((U1LSR&(1<<5))==0);

		ptr++;

	}

}


void uart1_tx_integer(int num)
{

	char buf[10];

	sprintf(buf,"%d",num);

	uart1_tx_string(buf);

}




void uart1_tx_hex(int num)
{

	char buf[10];

	sprintf(buf,"%X",num);

	uart1_tx_string(buf);

}

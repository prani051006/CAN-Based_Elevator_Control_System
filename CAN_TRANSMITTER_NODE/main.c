#include<lpc21xx.h>
#include "header.h"

#define upswitch 1<<14
#define downswitch 1<<15
#define emergence_sw 1<<16
#define buzzer 1<<17
#define motor 1<<12

signed char count=0;
int upflag=0,downflag=0,em_sw_flag=0;

void eme_switch1(void) __irq
{
	EXTINT=1<<0;
	uart1_tx_string("EMER_BUT");
	em_sw_flag=1;
	VICVectAddr=0;
}

void upswitch1(void) __irq
{
	EXTINT=1<<1;
	uart1_tx_string("UP");
	upflag=1;
	VICVectAddr=0;	
}

void downswitch1(void) __irq
{
	EXTINT=1<<2;
	uart1_tx_string("DOWN");
	downflag=1;
	VICVectAddr=0;
}


int main()
{
	CAN2_DF m1;
	IODIR0|=buzzer|motor;
	IOSET0|=buzzer;
	IOCLR0|=motor;
	PINSEL0|=0xA0000000; //PO.14 AS EINT1 AND P0.15 AS EINT2
	PINSEL1|=0X1; //P0.16 AS EINT0
	can2_init();
	LCD_INIT();
	uart1_init(115200);

	VICIntSelect=0;

	VICVectCntl0=(0X20)|14;
	VICVectAddr0=(unsigned long)eme_switch1;

	VICVectCntl1=(0X20)|15;
	VICVectAddr1=(unsigned long)upswitch1;
	
	VICVectCntl2=(0X20)|16;
	VICVectAddr2=(unsigned long)downswitch1;
	
	EXTMODE=0X07;
	EXTPOLAR=0X00;
	VICIntEnable=(1<<14)|(1<<15)|(1<<16);

	m1.id=0x000001AF;
	m1.rtr=0;//data frame
	m1.dlc=4;

	LCD_STRING("CAN BASED ELEVATOR SYSTEM");
	delay_sec(3);
	while(1)
	{
		
		if(upflag==1)
		{
			upflag=0;
			count++;
			if(count>=3)
				count=3;
			IOSET0=motor;
			delay_sec(3);
			IOCLR0=motor;

		}
		if(downflag==1)
		{
			downflag=0;
			count--;
			if(count<=0)
				count=0;
			IOSET0=motor;
			delay_sec(3);
			IOCLR0=motor;
		}
		if(em_sw_flag==1)
		{
			em_sw_flag=0;	
			LCD_CMD(0X01);
			LCD_STRING("...EMERGENGY...");
			IOCLR0=buzzer;
			delay_sec(3);
			IOSET0=buzzer;

		}

		LCD_CMD(0X01);
		if(count==0)
			LCD_STRING("GROUND FLOOR");
		else
		{
			LCD_CMD(0X01);
			LCD_STRING("FLOOR:");
			LCD_INTEGER(count);
		}
		
		m1.byteA=count;
		m1.byteB=0;
		can2_tx(m1);

		delay_sec(1);
	}
}


#include<lpc21xx.h>
#include"header.h"
#define LCD_D 0xff<<0
#define RS 1<<10
#define E 1<<11


void LCD_CMD(unsigned char cmd)
{
	IOCLR0=LCD_D;//TO CLEAR THE DATA PINS
	IOSET0=cmd; //assigning commad to the data pins
	IOCLR0=RS; //TO SELECT COMMAND REGISTER			r
	IOSET0=E; //TO LATCH THE DATA TO THE LCD
	delay_ms(2);//wait for 2 millisecond 
	//lcd is in internar operation mode
	IOCLR0=E; //TO RE-LATCH THE NEXT BYTE
}
void LCD_INIT(void)
{
	IODIR0|=LCD_D|RS|E;
	LCD_CMD(0x01);//to clear display
	LCD_CMD(0X02);//RETUREN CURSOR TO THE HOME POSITION
	LCD_CMD(0X0C);//DISPLAY ON ,CURSOR OFF
 	LCD_CMD(0X38);//8-BIT INTERFACING MODE WITH BOTH LINES
	LCD_CMD(0X80);//SELECT STARTING ADDRESS OF DDRAM
}


void LCD_DATA(unsigned char d)
{
	IOCLR0=LCD_D;//TO CLEAR THE DATA PINS
	IOSET0=d; //ASSIGNING DATA TO THE DATA PINS
	IOSET0=RS; //TO SELECT DATA REGISTER
	IOSET0=E;//TO LATCH THE DATA TO THE LCD
	delay_ms(2);
	IOCLR0=E;//TO RE-LATCH THE NEXT BYTE
}

void LCD_STRING(unsigned char* s)
{
	int pos=1;
	while(*s)
	{
		LCD_DATA(*s++);
		++pos;
		if(pos==16)
			LCD_CMD(0XC0);
	
	}
}

void LCD_INTEGER(int n)
{
	unsigned char arr[200];
	signed char i=0;
	if(n==0)
		LCD_DATA('0');
	else
	{
		if(n<0)
		{
			LCD_DATA('-');
			n=-n;
		}
		while(n>0)
		{
			arr[i++]=n%10;
			n=n/10;
		}
		for(i=i-1;i>=0;i--)
			LCD_DATA(arr[i]+48);
	}
}
	

#ifndef __HEADER_H_

#define __HEADER_H_

typedef unsigned int u32;

//LCD FUNCTION DECLARATION
void LCD_CMD(unsigned char cmd);
void LCD_INIT(void);
void LCD_DATA(unsigned char d);
void LCD_STRING(unsigned char* s);
void LCD_INTEGER(int n);

void delay_sec(unsigned int sec);
void delay_ms(unsigned int ms);

//UART DRIVER DECLARATION
void uart1_init(unsigned int baud);
void uart1_tx(unsigned char data);
unsigned char uart1_rx(void);
void uart1_tx_string(char *ptr);


typedef struct DATAFRAME

{

	u32 id;

	u32 rtr;

	u32 dlc;

	u32 byteA;

	u32 byteB;

}CAN2_DF;

void can2_init(void);

void can2_tx(CAN2_DF m1);

void can2_rx(CAN2_DF *m1);

#endif

/*
 * Uart_TEST.c
 *
 * Created: 12/19/2019 8:10:47 PM
 * Author : Zeyad
 */ 

//#include <avr/io.h>
#include "DIO_H.h"
#include "UART.h"
#define F_CPU 8000000UL
#include <util/delay.h>

volatile uint8_t flag = 0;
volatile uint8_t flag2 = 0;

                                             /********SENDER*****/
int main(void)
{
	DIO_SetPinDirection(12,OUTPUT);
	DIO_SetPinDirection(13,OUTPUT);
	DIO_WritePin(PA0,LOW);
	
	DIO_SetPinDirection(20,OUTPUT);
	
	DIO_SetPinDirection(22,OUTPUT);
	//volatile uint8_t read;
     
     str_UartConfg_t s={9600UL,_8BITS_MODE,INTERRUPT};
	 UART_init(&s);
	 uint8_t data = 0;
    while (1) 
    {     
		UART_recieveByte(&data);  
		_delay_ms(1000);
		if (flag == 1)
		{
			DIO_WritePin(20,LOW);
		}else
		{
			DIO_WritePin(20,HIGH);
		}
		
		if (flag2 == 1)
		{
			DIO_WritePin(22,LOW);
		}else
		{
			DIO_WritePin(22,HIGH);
		}
    }
}

ISR(USART_RXC_vect)
{
	flag2 = 1;
}

ISR(USART_UDRE_vect)
{
	flag = 1;
}
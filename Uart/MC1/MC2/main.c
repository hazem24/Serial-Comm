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

                                             /********SENDER*****/
int main(void)
{
	DIO_SetPinDirection(12,OUTPUT);
	DIO_SetPinDirection(13,OUTPUT);
	DIO_WritePin(PA0,LOW);
	
	volatile uint8_t read;
     
     str_UartConfg_t s={9600UL,_8BITS_MODE,POLLING};
	UART_init(&s);
	
    while (1) 
    {
		UART_recieveByte(&read);
		
		if (read==1)
		{
			DIO_WritePin(12,HIGH);
			DIO_WritePin(13,LOW);
		} 
		else if(read==2)
		{
		   DIO_WritePin(13,HIGH);
		   DIO_WritePin(12,LOW);
		}
        
		_delay_ms(2000);
		
    }
}


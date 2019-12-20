/*
 * SPI_test_MC1.c
 *
 * Created: 12/20/2019 5:54:59 PM
 * Author : Zeyad
 */ 

//#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "SPI.h"
/*
typedef struct
{
	uint8_t u8MasterSlave;
	uint8_t u8PreScaller;
	uint8_t u8InterruptPolling;
	uint8_t u8DataOrder;
	uint8_t u8ClockPolarity;
	uint8_t u8ClockPhase;
	
}str_SpiConfg_t;*/

int main(void)
{
    
	DIO_SetPinDirection(PB0,OUTPUT);
	
	str_SpiConfg_t s;
	s.u8MasterSlave=MASTER;
	s.u8PreScaller=CLK_4;
	DIO_SetPinDirection(PA0,INPUT);
	volatile uint8_t read;
	SPI_Init(&s);
    while (1) 
    {
		read=DIO_ReadPin(PA0);
		
		SPI_SendByte(read);
		_delay_ms(100);
		
		
    }
}


/*
 * SPI_MC2.c
 *
 * Created: 12/20/2019 8:04:59 PM
 * Author : Zeyad
 */ 

//#include <avr/io.h>
#include "SPI.h"


int main(void)
{
    /* Replace with your application code */
	str_SpiConfg_t s;
	s.u8MasterSlave=SLAVE;
	s.u8PreScaller=CLK_4;
	uint8_t read;
	DIO_SetPinDirection(PA0,OUTPUT);
	SPI_Init(&s);
    while (1) 
    {
		read=SPI_ReciveByte();
		
		if (read==HIGH)
		{
			DIO_WritePin(PA0,HIGH);
		} 
		else if(read==LOW)
		{
			DIO_WritePin(PA0,LOW);
		}
    }
}


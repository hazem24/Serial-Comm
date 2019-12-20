/*
 * SPI.c
 *
 * Created: 12/20/2019 5:55:58 PM
 *  Author: Zeyad
 */ 


/*- INCLUDES ----------------------------------------------*/
#include "SPI.h"
#include "SPI_config.h"
/*- LOCAL MACROS ------------------------------------------*/
/*- LOCAL Dataypes ----------------------------------------*/
/*- LOCAL FUNCTIONS PROTOTYPES ----------------------------*/
static void SettingSpiPrescaller(uint8_t prescaller);

/*- GLOBAL STATIC VARIABLES -------------------------------*/
/*- GLOBAL EXTERN VARIABLES -------------------------------*/
/*- LOCAL FUNCTIONS IMPLEMENTATION ------------------------*/

static void SettingSpiPrescaller(uint8_t prescaller)
{
	switch(prescaller)
	{
		case (CLK_4):
		
		SPCR &= 0xFC;
		SPCR|=CLK_4;
		
		
		break;
		
		case (CLK_16):
		
		SPCR &= 0xFC;
		SPCR|=CLK_16;
		
		break;
		
		case (CLK_64):
		
		SPCR &= 0xFC;
		SPCR|=CLK_64;
		
		break;
		
		case (CLK_128):
		
		SPCR &= 0xFC;
		SPCR|=CLK_128;
		
		break;
	}
}
/*- APIs IMPLEMENTATION -----------------------------------*/

/*************************************************************
*Description: Initialization of SPI Module
* Input     : pointer to spi configuration struct
* Output    : Error Status
* */

extern uint8_t SPI_Init(str_SpiConfg_t *Spi_config)
{
	uint8_t u8Error = ERROR_OK;
	
	if ( (Spi_config->u8MasterSlave != MASTER) && (Spi_config->u8MasterSlave !=SLAVE) )
	{
	     u8Error = ERROR_MAST_SLAVE;
	
	} 
	else
	{  
	   if ( ((Spi_config->u8PreScaller)!= CLK_4) && ((Spi_config->u8PreScaller)!= CLK_16) && ((Spi_config->u8PreScaller)!= CLK_64) && ((Spi_config->u8PreScaller)!= CLK_128) )
	   {
		   u8Error = ERROR_PRESCAL;
		  
	   } 
	   else
	   {
		    
		   switch (Spi_config->u8MasterSlave)   /***SET SPI DIRECTIONS FOR MASTER AND SLAVE*****/
		   {
			   case (MASTER):
			   
			   DIO_SetPinDirection(PB4,OUTPUT);
			   DIO_SetPinDirection(PB5,OUTPUT);
			   DIO_SetPinDirection(PB6,INPUT);
			   DIO_SetPinDirection(PB7,OUTPUT);
			   
			  // SPCR = (1<<SPE) | (1<<MSTR);
			   SETBIT(SPCR,MSTR);
			   
			   break;
			   
			   case (SLAVE):
			   
			   DIO_SetPinDirection(PB4,INPUT);
			   DIO_SetPinDirection(PB5,INPUT);
			   DIO_SetPinDirection(PB6,OUTPUT);
			   DIO_SetPinDirection(PB7,INPUT);
			   CLRBIT(SPCR,MSTR);
			   
			   break;
		   }
		   
		   /*********SETTING PRESCALLER*************/
		   SettingSpiPrescaller(Spi_config->u8PreScaller);
		   
		   /**SETTING DATA ORDER**/
		   CLRBIT(SPCR,CPOL);
		   CLRBIT(SPCR,CPHA);
		   
		   CLRBIT(SPCR,DORD);
		   SETBIT(SPCR,SPE);                /**ENABLE SPI MODULE**/
		   
	   }
	   
	}
	return u8Error;
}





/*************************************************************
*Description: Sending byte using spi
* Input     : byte to send
* Output    : Error Status
* */
extern uint8_t SPI_SendByte(uint8_t u8Data)
{
	
	SPDR = u8Data;
	while(BIT_IS_CLEAR(SPSR,SPIF)){}
		
		return 1;	
}

/*************************************************************
*Description: Receiving byte using spi
* Input     : poiter to data read data in it
* Output    : Error Status
* */
extern uint8_t SPI_ReciveByte(void)
{
   while(BIT_IS_CLEAR(SPSR,SPIF)){} 
    
   
   return SPDR;
}


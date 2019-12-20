/*
 * SPI.h
 *
 * Created: 12/20/2019 5:56:32 PM
 *  Author: Zeyad
 */ 


#ifndef SPI_H_
#define SPI_H_

/*- INCLUDES -----------------------------------------------*/

#include "REGISTERS.h"
#include "MACROS.h"
#include "STD_TYPES.h"
#include "DIO_H.h"

/*- CONSTANTS ----------------------------------------------*/

/*- PRIMITIVE TYPES ----------------------------------------*/
typedef struct
{
  uint8_t u8MasterSlave;
  uint8_t u8PreScaller;
  uint8_t u8InterruptPolling;
  uint8_t u8DataOrder;
  uint8_t u8ClockPolarity;
  uint8_t u8ClockPhase;
  
}str_SpiConfg_t;

/*- ENUMS --------------------------------------------------*/
/*- STRUCTS AND UNIONS -------------------------------------*/
/*- FUNCTION-LIKE MACROS -----------------------------------*/
#define MASTER 0U
#define SLAVE  1U

 
#define CLK_4   0U
#define CLK_16  1U
#define CLK_64  2U
#define CLK_128 3u





/***ERROR TYPES**/
#define ERROR_OK 0U
#define ERROR_MAST_SLAVE 1U
#define ERROR_PRESCAL 2U
/*- FUNCTION DECLARATIONS ----------------------------------*/

/*************************************************************
*Description: Initialization of SPI Module
* Input     : pointer to spi configuration struct
* Output    : Error Status
* */
extern 
uint8_t SPI_Init(str_SpiConfg_t *Spi_config);

/*************************************************************
*Description: Sending byte using spi
* Input     : byte to send
* Output    : Error Status
* */
extern uint8_t SPI_SendByte(uint8_t u8Data);


/*************************************************************
*Description: Receiving byte using spi
* Input     : poiter to data read data in it
* Output    : Error Status
* */
extern uint8_t SPI_ReciveByte(void);




#endif /* SPI_H_ */
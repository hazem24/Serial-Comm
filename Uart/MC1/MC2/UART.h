/*
 * UART.h
 *
 * Created: 12/19/2019 8:11:22 PM
 *  Author: Zeyad
 */ 


#ifndef UART_H_
#define UART_H_



/*- INCLUDES -----------------------------------------------*/


#include "STD_TYPES.h"
#include "MACROS.h"
#include "REGISTERS.h"
/*- CONSTANTS ----------------------------------------------*/
/*- PRIMITIVE TYPES ----------------------------------------*/
typedef struct
{
	uint32_t u32_BaudRate;
	uint8_t u8_DataBits;  /* (5~9) bits */
	uint8_t u8_FlagAction;  /***interrupt or polling***/
	
}str_UartConfg_t;
/*- ENUMS --------------------------------------------------*/
/*- STRUCTS AND UNIONS -------------------------------------*/

/*- FUNCTION-LIKE MACROS -----------------------------------*/
#define _5BITS_MODE  5U
#define _6BITS_MODE  6U
#define _7BITS_MODE  7U
#define _8BITS_MODE  8U
#define _9BITS_MODE  9U

#define DISABLE 0U
#define ENABLE 1U
#define ONE_STOP_BIT 0U
#define TWO_STOP_BITS 1U

#define INTERRUPT 0U
#define POLLING 1U

#define NO_PARITY 0U
#define EVEN_PARITY 


/*- FUNCTION DECLARATIONS ----------------------------------*/
/*************************************************************
*Description: Initialization of Uart Module
* Input     : poiter to uart configuration struct
* Output    : Error Status
* */
uint8_t UART_init(str_UartConfg_t * uart_config);

/*************************************************************
*Description: Sending byte of data
* Input     : u16Data to send
* Output    : Error Status
* */
uint8_t UART_sendByte(const uint8_t u8_Data);

/*************************************************************
*Description: Receiving byte of data
* Input     : pointer to u16Data
* Output    : Error Status
* */
uint8_t UART_recieveByte(uint8_t *u8_Data);


uint8_t UART_sendString(const uint16_t *Str);

uint8_t UART_receiveString(uint16_t * Str);









#endif /* UART_H_ */
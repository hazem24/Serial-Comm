/*
 * DIO_H.h
 *
 * Created: 11/1/2019 5:34:42 PM
 *  Author: Zeyad
 */ 


#ifndef DIO_H_H_
#define DIO_H_H_

/*- INCLUDES -----------------------------------------------*/
#include "STD_TYPES.h"
#include "REGISTERS.h"
#include "MACROS.h"

/*- MACROS -------------------------------------------------*/

#define  PA0 0
#define  PA1 1
#define  PA2 2
#define  PA3 3
#define  PA4 4
#define  PA5 5
#define  PA6 6
#define  PA7 7

#define  PB0 8
#define  PB1 9 
#define  PB2 10
#define  PB3 11
#define  PB4 12
#define  PB5 13
#define  PB6 14 
#define  PB7 15

#define  PC0 16
#define  PC1 17
#define  PC2 18
#define  PC3 19
#define  PC4 20 
#define  PC5 21
#define  PC6 22
#define  PC7 23

#define  PD0 24
#define  PD1 25
#define  PD2 26
#define  PD3 27
#define  PD4 28
#define  PD5 29
#define  PD6 30
#define  PD7 31

#define INPUT 0
#define HIGH 1
#define LOW  0
//-------------
#define INPUT  0
#define OUTPUT 1


#define porta 0
#define portb 1
#define portc 2
#define portd 3

/*- FUNCTION DECLARATIONS ----------------------------------*/

extern void DIO_SetPinDirection(uint8_t PinNumber,uint8_t Direction);
extern void DIO_WritePin(uint8_t PinNumber,uint8_t Value);
extern uint8_t  DIO_ReadPin(uint8_t PinNumber);
extern void DIO_ActivatePullUp(uint8_t PinNumber,uint8_t Value);
extern void DIO_SetPortDirection(uint8_t PortNumber,uint8_t Direction);
extern void DIO_WritePort (uint8_t PortNumber,uint8_t Value);
extern uint8_t  DIO_ReadPort(uint8_t PortNumber);




#endif /* DIO_H_H_ */
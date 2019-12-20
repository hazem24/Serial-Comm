/*
 * REGISTERS.h
 *
 * Created: 11/1/2019 5:30:41 PM
 *  Author: Zeyad
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "STD_TYPES.h"


#define PORTA *((volatile uint8_t*) 0x3B)
#define DDRA  *((volatile uint8_t*) 0x3A)
#define PINA  *((volatile uint8_t*) 0x39)


#define PORTB *((volatile uint8_t*) 0x38)
#define DDRB  *((volatile uint8_t*) 0x37)
#define PINB  *((volatile uint8_t*) 0x36)


#define PORTC *((volatile uint8_t*) 0x35)
#define DDRC  *((volatile uint8_t*) 0x34)
#define PINC  *((volatile uint8_t*) 0x33)


#define PORTD *((volatile uint8_t*) 0x32)
#define DDRD  *((volatile uint8_t*) 0x31)
#define PIND  *((volatile uint8_t*) 0x30)


///timer registers
#define TCNT0 *((volatile uint8_t*) 0x52)

#define TIFR  *((volatile uint8_t*) 0x58) 
#define TCCR0 *((volatile uint8_t*) 0x53)
#define TIMSK *((volatile uint8_t*) 0x59)
#define SREG *((volatile uint8_t*) 0x5F)
#define OCR0 *((volatile uint8_t*) 0x5C)

#define MCUCR *((volatile uint8_t*) 0x55)

#define FOC0 7
#define WGM00 6
#define WGM01 3
#define CS00 0
#define CS01 1
#define CS02 2
#define OCIE0 1
#define TOIE0   0	
#define OCF0 1

/***uart registers**/

#define UDR  *((volatile uint8_t*) 0x2C)
#define UCSRA  *((volatile uint8_t*) 0x2B)
#define UCSRB  *((volatile uint8_t*) 0x2A)
#define UBBRRL *((volatile uint8_t*) 0x29)
#define UBBRRH  *((volatile uint8_t*) 0x40)
#define UCSRC  *((volatile uint8_t*) 0x40)

#define UCSRA_MPCM  0U
#define UCSRA_U2X   1U
#define UCSRA_PE    2U
#define UCSRA_DOR   3U
#define UCSRA_FE    4U
#define UCSRA_UDRE  5U
#define UCSRA_TXC   6U
#define UCSRA_RXC   7U


#define UCSRB_RXCIE  7
#define UCSRB_TXCIE  6
#define UCSRB_UDRIE  5
#define UCSRB_RXEN   4
#define UCSRB_TXEN   3
#define UCSRB_UCSZ2  2
#define UCSRB_RXB8   1
#define UCSRB_TXB8   0

#define UCSRC_URSEL  7
#define UCSRC_UMSEL  6
#define UCSRC_UPM1   5
#define UCSRC_UPM0   4
#define UCSRC_USBS   3
#define UCSRC_UCSZ1  2
#define UCSRC_UCSZ0  1
#define UCSRC_UCPOL  0

#endif /* REGISTERS_H_ */
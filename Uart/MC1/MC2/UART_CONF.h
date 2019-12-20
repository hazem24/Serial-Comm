/*
 * UART_CONF.h
 *
 * Created: 12/20/2019 1:35:01 AM
 *  Author: Zeyad
 */ 


#ifndef UART_CONF_H_
#define UART_CONF_H_

/*****************freq.****************/
#define UART_FCPU 8000000UL

/***********interrupts******************/
#define UART_TX_INTTERTUPT   ENABLE    /*ENABLE OR DISABLE**/
#define UART_RX_INTTERTUPT   ENABLE  /*ENABLE OR DISABLE**/
#define UART_UDRE_INTTERTUPT ENABLE  /*ENABLE OR DISABLE**/

#define STOP_BITS  ONE_STOP_BIT  /* 0/1 */




/********************parity*********************/

#endif /* UART_CONF_H_ */
/*- INCLUDES ----------------------------------------------*/
#include "UART.h"
#include "UART_CONF.h"


/*- LOCAL MACROS ------------------------------------------*/
#define UART_INIT_SUCCESS 0
#define UART_INIT_FAIL 1


extern uint8_t flag;
extern uint8_t flag2;



#define SHIFT_8_BITS 8UL
/*- LOCAL Dataypes ----------------------------------------*/


/*- LOCAL FUNCTIONS PROTOTYPES ----------------------------*/
static void Set_StopBits(void);

static void Enable_Intterupt_Mask(void);
/*- GLOBAL STATIC VARIABLES -------------------------------*/
static uint8_t response_type = 0;/* Polling or interrupt response back. */
/*- GLOBAL EXTERN VARIABLES -------------------------------*/
/*- LOCAL FUNCTIONS IMPLEMENTATION ------------------------*/

static void Set_StopBits(void)   /**function to set stop bit (1 or 2) stop bits**/
{
	#if (STOP_BITS==ONE_STOP_BIT)
	
	CLRBIT(UCSRC,UCSRC_USBS);
	
	#elif (STOP_BITS==TWO_STOP_BITS)
	
	SETBIT(UCSRC,UCSRC_USBS);
	
	#else
	
	#error "UNDEFINED STOP BITS NUMBER"
	
	#endif
}

static void Enable_Intterupt_Mask(void)  /**function to enable specified interrupt mask**/
{
	sei();
	#if (UART_TX_INTTERTUPT==ENABLE)
	SETBIT(UCSRB,UCSRB_TXCIE);
	#endif
	
	#if (UART_RX_INTTERTUPT==ENABLE)
	SETBIT(UCSRB,UCSRB_RXEN);
	#endif
	
	#if (UART_UDRE_INTTERTUPT==ENABLE)
	SETBIT(UCSRB,UCSRB_UDRIE);
	#endif	
}

/*- APIs IMPLEMENTATION -----------------------------------*/
/*************************************************************
*Description: Initialization of UART Module
* Input     : POINTER to UART configuration struct
* Output    : Error Status
* */
uint8_t UART_init(str_UartConfg_t * uart_config)
{
	uint8_t Error = UART_INIT_SUCCESS;
	
	uint16_t u16_UBRR_Value;
	
	if ( ((uart_config->u32_BaudRate)<2400) || ((uart_config->u32_BaudRate)%300 !=0))
	{
		Error = UART_INIT_FAIL;
	}
	else
	{
		if ((uart_config->u8_DataBits >_9BITS_MODE)  || (uart_config->u8_DataBits<_5BITS_MODE))
		{
			Error = UART_INIT_FAIL;
		}
		else
		{
			if ( (uart_config->u8_FlagAction!=INTERRUPT) && (uart_config->u8_FlagAction!=POLLING) )
			{
				Error = UART_INIT_FAIL;
			}
			else
			{
				u16_UBRR_Value = (uint16_t)((UART_FCPU / (16UL * (uart_config->u32_BaudRate)))-1UL );
				
				SETBIT(UCSRB,UCSRB_TXEN);
				SETBIT(UCSRB,UCSRB_RXEN);
				
				switch (uart_config->u8_DataBits)    /*******switch between (5~9bits)modes******/
				{
					case (_5BITS_MODE):
					
					CLRBIT(UCSRC,UCSRC_UCSZ0);
					CLRBIT(UCSRC,UCSRC_UCSZ1);
					CLRBIT(UCSRB,UCSRB_UCSZ2);
					
					break;
					
					case (_6BITS_MODE):
					
					SETBIT(UCSRC,UCSRC_UCSZ0);
					CLRBIT(UCSRC,UCSRC_UCSZ1);
					CLRBIT(UCSRB,UCSRB_UCSZ2);
					
					break;
					
					case (_7BITS_MODE):
					
					CLRBIT(UCSRC,UCSRC_UCSZ0);
					SETBIT(UCSRC,UCSRC_UCSZ1);
					CLRBIT(UCSRB,UCSRB_UCSZ2);

					break;
					
					case (_8BITS_MODE):
					
					SETBIT(UCSRC,UCSRC_UCSZ0);
					SETBIT(UCSRC,UCSRC_UCSZ1);
					CLRBIT(UCSRB,UCSRB_UCSZ2);
					
					break;
					
					case (_9BITS_MODE):
					
					SETBIT(UCSRC,UCSRC_UCSZ0);
					SETBIT(UCSRC,UCSRC_UCSZ1);
					SETBIT(UCSRB,UCSRB_UCSZ2);
					
					break;
					
					default:
					break;
				}
				
				/**setting stop bits ( 1 or 2 )**/
				/**call function */
				Set_StopBits();
				
				
				if (uart_config->u8_FlagAction==INTERRUPT)
				{
					/*call function enable interrupts masks*/
					response_type = INTERRUPT;
					Enable_Intterupt_Mask();
				}
				else
				{
					/**do nothing for polling mode**/
					response_type = POLLING;
				}
				
				SETBIT(UCSRC,UCSRC_URSEL);  /*to select UBBRH*/
				UBBRRH = (uint8_t)(u16_UBRR_Value>>SHIFT_8_BITS);

				UBBRRL = (uint8_t)u16_UBRR_Value;
				SETBIT(PORTB,7);
			}
		}
	}
	return Error;
}







/*************************************************************
*Description: Sending byte of data
* Input     : u16Data to send
* Output    : Error Status
* */
uint8_t UART_sendByte(const uint8_t u8_Data)
{
	if (response_type == INTERRUPT)
	{
		if (!BIT_IS_CLEAR(UCSRA,UCSRA_UDRE))
		{
			UDR = u8_Data;
		}else
		{
			/* Error Overwrite Data Must Be Here!. */
		}
	}
	else
	{
		while(BIT_IS_CLEAR(UCSRA,UCSRA_UDRE)){}
		UDR = u8_Data;
	}	
	return 1;
}

/*************************************************************
*Description: Receiving byte of data
* Input     : pointer to u16Data
* Output    : Error Status
* */
uint8_t UART_recieveByte(uint8_t *u8_Data)
{
	if (response_type == INTERRUPT)
	{
		if (BIT_IS_SET(UCSRA,UCSRA_RXC))
		{
			*u8_Data = UDR;/* No interrupt happen. */
		}else
		{
			/* Error Overwrite Data Must Be Here!. */
		}
	}
	else
	{
		while(BIT_IS_CLEAR(UCSRA,UCSRA_RXC)){}
		*u8_Data=UDR;
	}	
	return 1;
}




/*- INCLUDES ----------------------------------------------*/
#include "UART.h"
#include "UART_CONF.h"

/*- LOCAL MACROS ------------------------------------------*/
#define UART_INIT_SUCCESS 0
#define UART_INIT_FAIL 1



#define SHIFT_8_BITS 8U
/*- LOCAL Dataypes ----------------------------------------*/


/*- LOCAL FUNCTIONS PROTOTYPES ----------------------------*/
static void Set_StopBits(void);

static void Enable_Intterupt_Mask(void);
/*- GLOBAL STATIC VARIABLES -------------------------------*/
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
*Description: Initialization of Uart Module
* Input     : poiter to uart configuration struct
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
				u16_UBRR_Value = (uint16_t)((UART_FCPU / (16U * (uart_config->u32_BaudRate)))-1U );
				
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
					Enable_Intterupt_Mask();
					
				}
				else
				{
					/**do nothing for polling mode**/
				}
				
				SETBIT(UCSRC,UCSRC_URSEL);  /*to select UBBRH*/
				
				UBBRRL = (uint8_t)u16_UBRR_Value;
				// UBBRRH = (uint8_t)(u16_UBRR_Value>>SHIFT_8_BITS);
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
	
	while(BIT_IS_CLEAR(UCSRA,UCSRA_UDRE)){}
	UDR = u8_Data;
	
	return 1;
}

/*************************************************************
*Description: Receiving byte of data
* Input     : pointer to u16Data
* Output    : Error Status
* */
uint8_t UART_recieveByte(uint8_t *u8_Data)
{
	while(BIT_IS_CLEAR(UCSRA,UCSRA_RXC)){}
	
	*u8_Data=UDR;
	
	//SETBIT(UCSRA,7);
	
	return 1;
}

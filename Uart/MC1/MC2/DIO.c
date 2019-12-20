/*
 * DIO.c
 *
 * Created: 11/1/2019 5:30:03 PM
 *  Author: Zeyad
 */ 

#include "DIO_H.h"

/*********Setting pin Direction Function********/

extern void DIO_SetPinDirection(uint8_t PinNumber,uint8_t Direction)
{
	
	
	
	if( (PinNumber>=0)&&(PinNumber<=7) )           //////////port a
	{
		  if (Direction == INPUT) 
		  {
			CLRBIT(DDRA, PinNumber);
		  } 
		  else 
		  {
			SETBIT(DDRA, PinNumber);
	      } 

    }
	else if ((PinNumber>=8)&&(PinNumber<=15))        ////////port b 
	{
		PinNumber=PinNumber-8;
		
		if (Direction == INPUT)
		{
			CLRBIT(DDRB,PinNumber);
		}
		else
		{
			SETBIT(DDRB,PinNumber);
		}

	}
	else if ((PinNumber>=16)&&(PinNumber<=23))        ////////port c
	{
		PinNumber=PinNumber-16;
		
		if (Direction == INPUT)
		{
			CLRBIT(DDRC,PinNumber);
		}
		else
		{
			SETBIT(DDRC,PinNumber);
		}

	}
	else if ((PinNumber>=24)&&(PinNumber<=31))        ////////port d
	{
		PinNumber=PinNumber-24;
		
		if (Direction == INPUT)
		{
			CLRBIT(DDRD,PinNumber);
		}
		else
		{
			SETBIT(DDRD,PinNumber);
		}

	}
	else
	{
		///////////do nothing///////////
	}
   
 
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/*********Setting Direction pin Function********/

extern void DIO_WritePin(uint8_t PinNumber,uint8_t Value)
{
	 ////////////// lazem acheck 3la el direction eno ouput
	 
	 if( (PinNumber>=0)&&(PinNumber<=7) )           //////////port a
	 {
		 if (Value == LOW)
		 {
			 CLRBIT(PORTA, PinNumber);
		 }
		 else
		 {
			 SETBIT(PORTA, PinNumber);
		 }

	 }
	 else if( (PinNumber>=8)&&(PinNumber<=15) )           //////////port b
	 {
		 PinNumber=PinNumber-8;
		 
		 if (Value == LOW)
		 {
			 CLRBIT(PORTB, PinNumber);
		 }
		 else
		 {
			 SETBIT(PORTB, PinNumber);
		 }

	 }
	 else if( (PinNumber>=16)&&(PinNumber<=23) )           //////////port c
	 {
		 PinNumber=PinNumber-16;
		 
		 if (Value == LOW)
		 {
			 CLRBIT(PORTC, PinNumber);
		 }
		 else
		 {
			 SETBIT(PORTC, PinNumber);
		 }

	 }
	 else if( (PinNumber>=24)&&(PinNumber<=31) )           //////////port d
	 {
		 PinNumber=PinNumber-24;
		 
		 if (Value == LOW)
		 {
			 CLRBIT(PORTD, PinNumber);
		 }
		 else
		 {
			 SETBIT(PORTD, PinNumber);
		 }

	 }
	
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/*********Activate Pull up resistor********/

extern void DIO_ActivatePullUp(uint8_t PinNumber,uint8_t Value)
{
	//////////////////    lazem acheck 3la el direction eno input 
	
	if( (PinNumber>=0)&&(PinNumber<=7) )           //////////port a
	{
		if (Value == LOW)
		{
			CLRBIT(PORTA, PinNumber);
		}
		else
		{
			SETBIT(PORTA, PinNumber);
		}

	}
	else if( (PinNumber>=8)&&(PinNumber<=15) )           //////////port b
	{
		PinNumber=PinNumber-8;
		
		if (Value == LOW)
		{
			CLRBIT(PORTB, PinNumber);
		}
		else
		{
			SETBIT(PORTB, PinNumber);
		}

	}
	else if( (PinNumber>=16)&&(PinNumber<=23) )           //////////port c
	{
		PinNumber=PinNumber-16;
		
		if (Value == LOW)
		{
			CLRBIT(PORTC, PinNumber);
		}
		else
		{
			SETBIT(PORTC, PinNumber);
		}

	}
	else if( (PinNumber>=24)&&(PinNumber<=31) )           //////////port d
	{
		PinNumber=PinNumber-24;
		
		if (Value == LOW)
		{
			CLRBIT(PORTD, PinNumber);
		}
		else
		{
			SETBIT(PORTD, PinNumber);
		}

	}
	
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*********Getting pin value********/

extern uint8_t  DIO_ReadPin(uint8_t PinNumber)
{     
	uint8_t value=0;
	
	if( (PinNumber>=0)&&(PinNumber<=7) )           //////////port a
	{
		
		value= (GETBIT(PINA,PinNumber));
		
	}
	else if( (PinNumber>=8)&&(PinNumber<=15) )           //////////port b
	{
		PinNumber=PinNumber-8;
		
		value= (GETBIT(PINB, PinNumber));
		
	}
	else if( (PinNumber>=16)&&(PinNumber<=23) )           //////////port c
	{
		PinNumber=PinNumber-16;
		
		value= (GETBIT(PINC,PinNumber));
		
	}
	else if( (PinNumber>=24)&&(PinNumber<=31) )           //////////port d
	{
		PinNumber=PinNumber-24;
		
		value= (GETBIT(PIND, PinNumber));
		
	}
	
return value;
	
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*********Setting Port Direction ********/
extern void DIO_SetPortDirection(uint8_t PortNumber,uint8_t Direction)
{
	if (PortNumber==porta)                /////////////////porta
	{
		if (Direction==INPUT)
		{
			DDRA=0x00;
		} 
		else if (Direction==OUTPUT)
		{
			DDRA=0xFF;
		}
		else
		{
			DDRA=Direction;
		}
	}
	else if (PortNumber==portb)       ///////////////portb
	{
		if (Direction==INPUT)
		{
			DDRB=0x00;
		}
		else if (Direction==OUTPUT)
		{
			DDRB=0xFF;
		}
		else
		{
			DDRB=Direction;
		}
		
	}
	else if (PortNumber==portc)       ///////////////portc
	{
		if (Direction==INPUT)
		{
			DDRC=0x00;
		}
		else if (Direction==OUTPUT)
		{
			DDRC=0xFF;
		}
		else
		{
			DDRC=Direction;
		}
		
	}
	else if (PortNumber==portd)       ///////////////portd
	{
		if (Direction==INPUT)
		{
			DDRD=0x00;
		}
		else if (Direction==OUTPUT)
		{
			DDRD=0xFF;
		}
		else
		{
			DDRD=Direction;
		}
		
	}
	
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/*********Setting Port Direction ********/

extern void DIO_WritePort(uint8_t PortNumber,uint8_t Value)
{
	if (PortNumber==porta)                /////////////////porta
	{
		if (Value==LOW)
		{
			PORTA=0x00;
		}
		else if (Value==OUTPUT)
		{
			PORTA=0xFF;
		}
		else
		{
			PORTA=Value;
		}
	}
	else if (PortNumber==portb)       ///////////////portb
	{
		if (Value==LOW)
		{
			PORTB=0x00;
		}
		else if (Value==HIGH)
		{
			PORTB=0xFF;
		}
		else
		{
			PORTB=Value;
		}
		
	}
	else if (PortNumber==portc)       ///////////////portc
	{
		if (Value==LOW)
		{
			PORTC=0x00;
		}
		else if (Value==HIGH)
		{
			PORTC=0xFF;
		}
		else
		{
			PORTC=Value;
		}
		
	}
	else if (PortNumber==portd)       ///////////////portd
	{
		if (Value==LOW)
		{
			PORTD=0x00;
		}
		else if (Value==HIGH)
		{
			PORTD=0xFF;
		}
		else
		{
			PORTD=Value;
		}
		
	}
	
}
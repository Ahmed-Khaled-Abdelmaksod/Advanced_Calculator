/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< DIO_program file >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * @author : Ahmed Khaled Abdelmaksod Ebrahim
 * @layer  : MCAL
 * @brief  : contains all implementation of DIO interfaces
 */
#include"DIO_interface.h"

/**
 * @brief Set the direction of a specific GPIO pin.
 *
 * @param pin   Pointer to the pin_t structure representing the GPIO pin.
 * @param direction   Desired direction for the GPIO pin (DIO_INPUT or DIO_OUTPUT).
 */
void DIO_setDirectonPin(const pin_t *pin,u8 direction)
{
	if(direction == DIO_INPUT)
	{
		switch(pin->port)
		{
		case PORTA_INDEX:
			CLEAR_BIT(DDRA,pin->pin);
			break;
		case PORTB_INDEX:
			CLEAR_BIT(DDRB,pin->pin);
			break;
		case PORTC_INDEX:
			CLEAR_BIT(DDRC,pin->pin);
			break;
		case PORTD_INDEX:
			CLEAR_BIT(DDRD,pin->pin);
			break;
		}
	}
	else if(direction == DIO_OUTPUT)
	{
		switch(pin->port)
		{
		case PORTA_INDEX:
			SET_BIT(DDRA,pin->pin);
			break;
		case PORTB_INDEX:
			SET_BIT(DDRB,pin->pin);
			break;
		case PORTC_INDEX:
			SET_BIT(DDRC,pin->pin);
			break;
		case PORTD_INDEX:
			SET_BIT(DDRD,pin->pin);
			break;
		}
	}
}


/**
 * @brief Write a logic level to a specific GPIO pin.
 *
 * @param pin   Pointer to the pin_t structure representing the GPIO pin.
 * @param level   Desired logic level for the GPIO pin (DIO_LOW or DIO_HIGH).
 */
void DIO_writeLogicPin(const pin_t *pin,u8 level)
{
	if(level == DIO_LOW)
		{
			switch(pin->port)
			{
			case PORTA_INDEX:
				CLEAR_BIT(PORTA,pin->pin);
				break;
			case PORTB_INDEX:
				CLEAR_BIT(PORTB,pin->pin);
				break;
			case PORTC_INDEX:
				CLEAR_BIT(PORTC,pin->pin);
				break;
			case PORTD_INDEX:
				CLEAR_BIT(PORTD,pin->pin);
				break;
			}
		}
		else if(level == DIO_HIGH)
		{
			switch(pin->port)
			{
			case PORTA_INDEX:
				SET_BIT(PORTA,pin->pin);
				break;
			case PORTB_INDEX:
				SET_BIT(PORTB,pin->pin);
				break;
			case PORTC_INDEX:
				SET_BIT(PORTC,pin->pin);
				break;
			case PORTD_INDEX:
				SET_BIT(PORTD,pin->pin);
				break;
			}
		}
}



/**
 * @brief Read the logic level of a specific GPIO pin.
 *
 * @param pin   Pointer to the pin_t structure representing the GPIO pin.
 * @return u8   Logic level of the GPIO pin (DIO_LOW or DIO_HIGH).
 */
u8 DIO_readLogicPin(const pin_t *pin)
{
	u8 local_pin = 0x00;
	switch(pin->port)
	{
	case PORTA_INDEX:
		local_pin = GET_BIT(PINA,pin->pin);
		break;
	case PORTB_INDEX:
		local_pin = GET_BIT(PINB,pin->pin);
		break;
	case PORTC_INDEX:
		local_pin = GET_BIT(PINC,pin->pin);
		break;
	case PORTD_INDEX:
		local_pin = GET_BIT(PIND,pin->pin);
		break;
	}
	return local_pin;
}


/**
 * @brief Initialize a specific GPIO pin based on the configuration in the pin_t structure.
 *
 * @param pin   Pointer to the pin_t structure representing the GPIO pin with its configuration.
 */
void DIO_initPin(const pin_t *pin)
{
	DIO_setDirectonPin(pin,pin->direction);
	DIO_writeLogicPin(pin,pin->logic);
}



/**
 * @brief Toggle the logic level of a specific GPIO pin.
 *
 * @param pin   Pointer to the pin_t structure representing the GPIO pin.
 */
void DIO_togglePin(pin_t *pin)
{
	switch(pin->port)
	{
	case PORTA_INDEX :
		TOGGLE_BIT(PORTA,pin->pin);
		break;
	case PORTB_INDEX :
		TOGGLE_BIT(PORTB,pin->pin);
		break;
	case PORTC_INDEX :
			TOGGLE_BIT(PORTC,pin->pin);
			break;
	case PORTD_INDEX :
			TOGGLE_BIT(PORTD,pin->pin);
			break;
	}

}

/**
 * @brief Set the direction of an entire GPIO port.
 *
 * @param port       The GPIO port to configure (e.g., PORTA_INDEX).
 * @param direction  Desired direction for the GPIO port (DIO_INPUT or DIO_OUTPUT).
 */
void DIO_setDirectonPort(u8 port,u8 direction)
{
	switch(port)
	{
	case PORTA_INDEX :
		DDRA = direction;
		break;
	case PORTB_INDEX :
		DDRB = direction;
		break;
	case PORTC_INDEX :
		DDRC = direction;
		break;
	case PORTD_INDEX:
		DDRD = direction;
		break;
	}
}



/**
 * @brief Write a logic level to an entire GPIO port.
 *
 * @param port   The GPIO port to write to (e.g., PORTA_INDEX).
 * @param level  Desired logic level for the GPIO port (DIO_LOW or DIO_HIGH).
 */
void DIO_writeLogicPort(u8 port,u8 level)
{
	switch(port)
		{
		case PORTA_INDEX :
			PORTA = level;
			break;
		case PORTB_INDEX :
			PORTB = level;
			break;
		case PORTC_INDEX :
			PORTC = level;
			break;
		case PORTD_INDEX:
			PORTD = level;
			break;
		}
}



/**
 * @brief Read the logic levels of an entire GPIO port.
 *
 * @param port   The GPIO port to read from (e.g., PORTA_INDEX).
 * @return u8    Logic levels of the GPIO port as a byte.
 */
u8 DIO_readLogicPort(u8 port)
{
	u8 local_port = 0x00;
	switch(port)
	{
	case PORTA_INDEX :
		local_port = PINA;
		break;
	case PORTB_INDEX :
		local_port = PINB;
		break;
	case PORTC_INDEX :
		local_port = PINC;
		break;
	case PORTD_INDEX:
		local_port = PIND;
		break;
	}
	return local_port;
}



/**
 * @brief Initialize an entire GPIO port with specified direction and initial logic levels.
 *
 * @param port       The GPIO port to initialize (e.g., PORTA_INDEX).
 * @param direction  Desired direction for the GPIO port (DIO_INPUT or DIO_OUTPUT).
 * @param logic      Initial logic levels for the GPIO port (DIO_LOW or DIO_HIGH).
 */
void DIO_initPort(u8 port,u8 direction,u8 logic)
{
	DIO_setDirectonPort(port,direction);
	DIO_writeLogicPort(port,logic);
}



/**
 * @brief Toggle the logic levels of all pins in a specified GPIO port.
 *
 * @param port   The GPIO port to toggle (e.g., PORTA_INDEX).
 */
void DIO_togglePort(u8 port)
{
	switch(port)
	{
	case PORTA_INDEX :
		PORTA ^= 0xFF;
		break;
	case PORTB_INDEX :
		PORTB ^= 0xFF;
		break;
	case PORTC_INDEX :
		PORTC ^= 0xFF;
		break;
	case PORTD_INDEX:
		PORTD ^= 0xFF;
		break;
	}
}




// Function to set direction (input/output) of higher nibble of a port
void DIO_setDirectionHigherNibble(u8 port, u8 direction) {
	// Define mask for higher nibble (pins 4-7) of port
	u8 mask = 0xF0;
	
	// Check if direction is 1 (output) or 0 (input)
	if (direction == DIO_OUTPUT) {
		// Set higher nibble pins to output
		switch (port) {
			case PORTA_INDEX:
			DDRA |= mask;
			break;
			case PORTB_INDEX:
			DDRB |= mask;
			break;
			case PORTC_INDEX:
			DDRC |= mask;
			break;
			case PORTD_INDEX:
			DDRD |= mask;
			break;
			default:
			// Invalid port
			break;
		}
		} else {
		// Set higher nibble pins to input
		switch (port) {
			case PORTA_INDEX:
			DDRA &= ~mask;
			break;
			case PORTB_INDEX:
			DDRB &= ~mask;
			break;
			case PORTC_INDEX:
			DDRC &= ~mask;
			break;
			case PORTD_INDEX:
			DDRD &= ~mask;
			break;
			default:
			// Invalid port
			break;
		}
	}
}


// Function to set direction (input/output) of lower nibble of a port
void DIO_setDirectionLowerNibble(u8 port, u8 direction) {
	// Define mask for lower nibble (pins 0-3) of port
	u8 mask = 0x0F;
	
	// Check if direction is DIO_OUTPUT or DIO_INPUT
	if (direction == DIO_OUTPUT) {
		// Set lower nibble pins to output
		switch (port) {
			case PORTA_INDEX:
			DDRA |= mask;
			break;
			case PORTB_INDEX:
			DDRB |= mask;
			break;
			case PORTC_INDEX:
			DDRC |= mask;
			break;
			case PORTD_INDEX:
			DDRD |= mask;
			break;
			default:
			// Invalid port
			break;
		}
		} else {
		// Set lower nibble pins to input
		switch (port) {
			case PORTA_INDEX:
			DDRA &= ~mask;
			break;
			case PORTB_INDEX:
			DDRB &= ~mask;
			break;
			case PORTC_INDEX:
			DDRC &= ~mask;
			break;
			case PORTD_INDEX:
			DDRD &= ~mask;
			break;
			default:
			// Invalid port
			break;
		}
	}
}


//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function connected internal pull up
 * Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
 	  =>Copy_u8ConnectPullup --> [DIO_PIN_HIGH , DIO_PIN_LOW ]
 * return : its status
 */
DIO_ErrorStatus DIO_enumConnectPullup (u8 Copy_u8PORT ,u8 Copy_u8PIN, u8 Copy_u8ConnectPullup)
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	if ((Copy_u8PORT <= PORTD_INDEX) && (Copy_u8PIN <= PIN7))
	{
		switch(Copy_u8PORT)
		{
		/* Connect or disconnect the pull up resistance to the given pin in port A */
		case PORTA_INDEX:
			if(Copy_u8ConnectPullup==DIO_HIGH)
			{
				CLEAR_BIT(SFIOR,2);
				CLEAR_BIT(DDRA,Copy_u8PIN);
				SET_BIT(DDRA,Copy_u8PIN);
			}
			else
			{
				CLEAR_BIT(PORTA,Copy_u8PIN);
			}
			break;
			/* Connect or disconnect the pull up resistance to the given pin in port B */
		case PORTB_INDEX:
			if(Copy_u8ConnectPullup==DIO_HIGH)
			{
				CLEAR_BIT(SFIOR,2);
				CLEAR_BIT(DDRB,Copy_u8PIN);
				SET_BIT(PORTB,Copy_u8PIN);
			}
			else
			{
				CLEAR_BIT(PORTB,Copy_u8PIN);
			}
			break;
			/* Connect or disconnect the pull up resistance to the given pin in port C */
		case PORTC_INDEX:
			if(Copy_u8ConnectPullup==DIO_HIGH)
			{
				CLEAR_BIT(SFIOR,2);
				CLEAR_BIT(DDRC,Copy_u8PIN);
				SET_BIT(PORTC,Copy_u8PIN);
			}
			else
			{
				CLEAR_BIT(PORTC,Copy_u8PIN);
			}
			break;
			/* Connect or disconnect the pull up resistance to the given pin in port D */
		case PORTD_INDEX:
			if(Copy_u8ConnectPullup==DIO_HIGH)
			{
				CLEAR_BIT(SFIOR,2);
				CLEAR_BIT(DDRD,Copy_u8PIN);
				SET_BIT(PORTD,Copy_u8PIN);
			}
			else
			{
				CLEAR_BIT(PORTD,Copy_u8PIN);
			}
			break;
		}
	}

	else
	{
		LOC_enumState = DIO_NOK ;
	}

	return LOC_enumState ;


}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<                          IO Pins                     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function set the direction of the Pin  (INPUT || OUTPUT)
 * Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
  	  =>Copy_u8Direction --> Pin Direction [ DIO_PIN_OUTPUT , DIO_PIN_INPUT ]
 * return : its status
 */
DIO_ErrorStatus DIO_enumSetPinDirection    (u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8Direction ) 
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((Copy_u8PORT <= PORTD_INDEX) && (Copy_u8PIN <= PIN7))
	{
		if ( Copy_u8Direction == DIO_OUTPUT )
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8PORT)
			{
			case PORTA_INDEX: SET_BIT(DDRA,Copy_u8PIN); break;
			case PORTB_INDEX: SET_BIT(DDRB,Copy_u8PIN); break;
			case PORTC_INDEX: SET_BIT(DDRC,Copy_u8PIN); break;
			case PORTD_INDEX: SET_BIT(DDRD,Copy_u8PIN); break;
			}
		}

		else if ( Copy_u8Direction == DIO_INPUT )
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8PORT)
			{
			case PORTA_INDEX: CLEAR_BIT(DDRA,Copy_u8PIN); break;
			case PORTB_INDEX: CLEAR_BIT(DDRB,Copy_u8PIN); break;
			case PORTC_INDEX: CLEAR_BIT(DDRC,Copy_u8PIN); break;
			case PORTD_INDEX: CLEAR_BIT(DDRD,Copy_u8PIN); break;
			}
		}

		else
		{
			LOC_enumState = DIO_NOK ;
		}
	}

	else
	{
		LOC_enumState = DIO_NOK ;
	}

	return LOC_enumState ;

}
//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Brief : This Function set the Value of the Pin  (HIGH || LOW)
 * Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
  	  =>Copy_u8Value --> Pin Direction [ DIO_PIN_HIGH , DIO_PIN_LOW ]
 * return : its status
 */
DIO_ErrorStatus DIO_enumSetPinValue      (u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8Value ) 
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((Copy_u8PORT <= PORTD_INDEX) && (Copy_u8PIN <= PIN7))
	{
		if (Copy_u8Value == DIO_HIGH)
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8PORT)
			{
			case PORTA_INDEX: SET_BIT(PORTA,Copy_u8PIN); break;
			case PORTB_INDEX: SET_BIT(PORTB,Copy_u8PIN); break;
			case PORTC_INDEX: SET_BIT(PORTC,Copy_u8PIN); break;
			case PORTD_INDEX: SET_BIT(PORTD,Copy_u8PIN); break;
			}

		}

		else if (Copy_u8Value == DIO_LOW)
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8PORT)
			{
			case PORTA_INDEX: CLEAR_BIT(PORTA,Copy_u8PIN); break;
			case PORTB_INDEX: CLEAR_BIT(PORTB,Copy_u8PIN); break;
			case PORTC_INDEX: CLEAR_BIT(PORTC,Copy_u8PIN); break;
			case PORTD_INDEX: CLEAR_BIT(PORTD,Copy_u8PIN); break;
			}
		}

		else
		{
			LOC_enumState = DIO_NOK ;
		}
	}

	else
	{
		LOC_enumState = DIO_NOK ;
	}

	return LOC_enumState ;

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Brief : This Function Get the Value of the Pin
 * Parameters :
 	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
  	  => *Copy_PtrData  --> pointer to recieve the pin value
 * return : its status and recieve Pin Value in pointer
 */

DIO_ErrorStatus DIO_enumGetPinValue          (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 * Copy_PtrData   )
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	if ((Copy_u8PORT <= PORTD_INDEX) && (Copy_u8PIN <= PIN7))
	{
		/* Check on the Required PORT Number */
		switch (Copy_u8PORT)
		{
		case PORTA_INDEX: * Copy_PtrData = GET_BIT(PINA,Copy_u8PIN); break;
		case PORTB_INDEX: * Copy_PtrData = GET_BIT(PINB,Copy_u8PIN); break;
		case PORTC_INDEX: * Copy_PtrData = GET_BIT(PINC,Copy_u8PIN); break;
		case PORTD_INDEX: * Copy_PtrData = GET_BIT(PIND,Copy_u8PIN); break;
		}
	}

	else
	{
		/* in case of error in the Pin ID or PORT ID */
		LOC_enumState = DIO_NOK ;
	}

	return LOC_enumState;
}
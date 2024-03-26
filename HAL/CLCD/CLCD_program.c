/*
 * CLCD_program.c
 *
 * Created: 23/03/2024 10:53:03 م
 *  Author: Ahmed Khaled
 */ 


/************************************************************************/
/* include section                                                      */
/************************************************************************/
#include<stdlib.h>
#include<math.h>
#include <util/delay.h>
#include"../../MCAL/DIO/DIO_interface.h"
#include"CLCD_interface.h"
// helper functions

static void CLCD_voidSetPort();
static void CLCD_voidSetNibble();
static void CLCD_voidEnable();

/************************************************************************/
/* position of RS, EN bits                                            */
/************************************************************************/

pin_t RS = {
	.direction = DIO_OUTPUT,
	.logic = DIO_LOW,
	.pin = PIN0,
	.port = PORTB_INDEX
};


pin_t EN = {
	.direction = DIO_OUTPUT,
	.logic = DIO_LOW,
	.pin = PIN1,
	.port = PORTB_INDEX
};

void CLCD_voidClcdInit()
{
	DIO_initPin(&RS);
	DIO_initPin(&EN);
	_delay_ms(50);
	#if CLCD_MODE_SELECTION == CLCD_8BIT_MODE
		CLCD_voidSetPort();
		_delay_ms(25);
		CLCD_voidSend8bitCommand(_LCD_8BIT_MODE_2LINE);
		_delay_ms(5);
		CLCD_voidSend8bitCommand(_LCD_8BIT_MODE_2LINE);
		_delay_us(150);
		CLCD_voidSend8bitCommand(_LCD_8BIT_MODE_2LINE);
		
		/* from data sheet*/
		CLCD_voidSend8bitCommand(_LCD_CLEAR_DISPLAY_);
		CLCD_voidSend8bitCommand(_LCD_RETURN_HOME_);
		CLCD_voidSend8bitCommand(_LCD_ENTRY_MODE_INC_SHIFT_OFF);
		CLCD_voidSend8bitCommand(_LCD_DISPLAY_ON_CURSOR_OFF_UNDERLINE_OFF);
		CLCD_voidSend8bitCommand(_LCD_START_DDRAM_ADR);
		CLCD_void8bitSetCursorPosition(0,1);
	#else
	/*
		CLCD_voidSetNibble();
		
		_delay_ms(20);
		CLCD_voidSend8bitCommand(0x33);
		_delay_ms(5);
		CLCD_voidSend8bitCommand(0x33);
		_delay_ms(150);
		CLCD_voidSend8bitCommand(0x33);
		
		/* from data sheet*/
		CLCD_voidSend8bitCommand(_LCD_CLEAR_DISPLAY_);
		CLCD_voidSend8bitCommand(_LCD_RETURN_HOME_);
		CLCD_voidSend8bitCommand(_LCD_ENTRY_MODE_INC_SHIFT_OFF);
		CLCD_voidSend8bitCommand(_LCD_DISPLAY_ON_CURSOR_OFF_UNDERLINE_OFF);
		CLCD_voidSend8bitCommand(_LCD_4BIT_MODE_2LINE);
		CLCD_voidSend8bitCommand(_LCD_START_DDRAM_ADR);
		*/
	#endif
}
void CLCD_void8bitSendData(u8 loc_u8Data)
{
	DIO_writeLogicPin(&RS,DIO_HIGH);
	#if CLCD_PORT_SELECTION == CLCD_PORTA
	DIO_writeLogicPort(PORTA_INDEX,loc_u8Data);
	#elif CLCD_PORT_SELECTION  == CLCD_PORTB
	DIO_writeLogicPort(PORTB_INDEX,loc_u8Data);
	#elif CLCD_PORT_SELECTION  == CLCD_PORTC
	DIO_writeLogicPort(PORTC_INDEX,loc_u8Data);
	#elif CLCD_PORT_SELECTION  == CLCD_PORTD
	DIO_writeLogicPort(PORTD_INDEX,loc_u8Data);
	#endif
	CLCD_voidEnable();
}
void CLCD_voidSend8bitCommand(u8 loc_u8Command)
{
	DIO_writeLogicPin(&RS,DIO_LOW);
	#if CLCD_PORT_SELECTION == CLCD_PORTA
	DIO_writeLogicPort(PORTA_INDEX,loc_u8Command);
	#elif CLCD_PORT_SELECTION  == CLCD_PORTB
	DIO_writeLogicPort(PORTB_INDEX,loc_u8Command);
	#elif CLCD_PORT_SELECTION  == CLCD_PORTC
	DIO_writeLogicPort(PORTC_INDEX,loc_u8Command);
	#elif CLCD_PORT_SELECTION  == CLCD_PORTD
	DIO_writeLogicPort(PORTD_INDEX,loc_u8Command);
	#endif
	CLCD_voidEnable();
}
void CLCD_void8bitSetCursorPosition(u8 loc_u8Row,u8 loc_u8Column)
{
	loc_u8Column--;
	switch(loc_u8Row)
	{
		case 1 : CLCD_voidSend8bitCommand(0x80 + loc_u8Column); break;
		case 2 : CLCD_voidSend8bitCommand(0xC0 + loc_u8Column); break;
		case 3 : CLCD_voidSend8bitCommand(0x94 + loc_u8Column); break;
		case 4 : CLCD_voidSend8bitCommand(0xD4 + loc_u8Column); break;
	}
}
void CLCD_void8bitSendString(u8* loc_ptrString)
{
	u8 loc_counter =0;
	while(loc_ptrString[loc_counter] != '\0')
	{
		CLCD_void8bitSendData(loc_ptrString[loc_counter]);
		loc_counter++;
	}
}


static void CLCD_voidSetPort()
{
	#if CLCD_PORT_SELECTION == CLCD_PORTA
		DIO_setDirectonPort(PORTA_INDEX,0XFF);
	#elif CLCD_PORT_SELECTION  == CLCD_PORTB
		DIO_setDirectonPort(PORTB_INDEX,0XFF);
	#elif CLCD_PORT_SELECTION  == CLCD_PORTC
		DIO_setDirectonPort(PORTC_INDEX,0XFF);
	#elif CLCD_PORT_SELECTION  == CLCD_PORTD
		DIO_setDirectonPort(PORTD_INDEX,0XFF);
	#endif
	
}

static void CLCD_voidSetNibble()
{
	#if CLCD_NIBBLE_POSITION == CLCD_LOWER_NIBBLE
		#if CLCD_PORT_SELECTION == CLCD_PORTA
			DIO_setDirectionHigherNibble(PORTA_INDEX,DIO_OUTPUT);
		#elif CLCD_PORT_SELECTION  == CLCD_PORTB
			DIO_setDirectionHigherNibble(PORTA_INDEX,DIO_OUTPUT);
		#elif CLCD_PORT_SELECTION  == CLCD_PORTC
			DIO_setDirectionHigherNibble(PORTA_INDEX,DIO_OUTPUT);
		#elif CLCD_PORT_SELECTION  == CLCD_PORTD
			DIO_setDirectionHigherNibble(PORTA_INDEX,DIO_OUTPUT);
		#endif
	#else
		#if CLCD_PORT_SELECTION == CLCD_PORTA
			DIO_setDirectionHigherNibble(PORTA_INDEX,DIO_OUTPUT);
		#elif CLCD_PORT_SELECTION  == CLCD_PORTB
			DIO_setDirectionHigherNibble(PORTB_INDEX,DIO_OUTPUT);
		#elif CLCD_PORT_SELECTION  == CLCD_PORTC
			DIO_setDirectionHigherNibble(PORTC_INDEX,DIO_OUTPUT);
		#elif CLCD_PORT_SELECTION  == CLCD_PORTD
			DIO_setDirectionHigherNibble(PORTD_INDEX,DIO_OUTPUT);
		#endif
	#endif
}




static void CLCD_voidEnable()
{
	DIO_writeLogicPin(&EN,DIO_HIGH);
	_delay_ms(1);
	DIO_writeLogicPin(&EN,DIO_LOW);
	_delay_ms(1);
}

void CLCD_voidSendNum(u32 loc_u32Num)
{
	u32 loc_u32IntegerPart = loc_u32Num;
	u8 loc_u8PowerOfIntegerPart = 0;
	u32 loc_u32MaxPower = 1;
	u8 loc_u8SendValue = 0;
	while (loc_u32IntegerPart > 0)
	{
		loc_u32IntegerPart /= 10;
		loc_u8PowerOfIntegerPart++;
	}
	loc_u8PowerOfIntegerPart--;
	loc_u32IntegerPart = loc_u32Num;
	loc_u32MaxPower = pow(10,loc_u8PowerOfIntegerPart);
	while (loc_u32MaxPower)
	{
		loc_u8SendValue = loc_u32IntegerPart / loc_u32MaxPower;
		loc_u32IntegerPart = loc_u32IntegerPart % loc_u32MaxPower;
		loc_u32MaxPower/=10;
		CLCD_void8bitSendData(loc_u8SendValue+'0');
	}
	
}
void CLCD_voidSendFloat(f64 loc_f64Data)
{
	u32 copy_s32Power = 1;
	s32 copy_u32Num = loc_f64Data;
	s32 copy_s32Iterator = 0;

	if (loc_f64Data == 0) {
		CLCD_void8bitSendData('0');									/*If the Result of operation = 0 then send '0' to Screen*/
		return;
	}
	if (loc_f64Data < 0) {								/*If the Result of operation is less than zero which mean it is negative number ex -5 send negative sign to LCD*/

		loc_f64Data = loc_f64Data * (-1);
		CLCD_void8bitSendData('-');
	}
	while (copy_u32Num)
	{
		copy_u32Num = copy_u32Num / 10;
		copy_s32Iterator++;
		copy_s32Power = copy_s32Power * 10;
	}
	s32 int_num = loc_f64Data * 10000;
	copy_s32Power = copy_s32Power * 1000;
	while (copy_s32Power > 0) {								/*Sending floating point to LCD*/
		copy_u32Num = int_num / copy_s32Power;
		int_num %= copy_s32Power;
		copy_s32Power /= 10;
		if (copy_s32Iterator == 0) {
			CLCD_void8bitSendData('.');
		}
		copy_s32Iterator--;
		CLCD_void8bitSendData(copy_u32Num + '0');				/*sending number digit by digit to LCD as char*/
	}
}
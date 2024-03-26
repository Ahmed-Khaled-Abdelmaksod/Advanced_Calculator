/*
 * main.c
 *
 * Created: 3/23/2024 5:12:57 PM
 *  Author: Ahmed Khaled Abdelmaksod Ebrahim
 */ 

#include <xc.h>
/************************************************************************/
/* INCLUDE SECTION                                                      */
/************************************************************************/
#include"HAL/KEYPAD/KEYPAD_interface.h"
#include"MCAL/DIO/DIO_interface.h"
#include "HAL/CLCD/CLCD_interface.h"
#include <util/delay.h>
/* Defined for the delays */
#define F_CPU 1000000UL

u8 value_u8 = '0'; /* used to store the value of passed key from keypad */
f32 global_f32FirstOperant = 0; /*first operant of the operation*/
f32 global_f32SecondOperant = 0; /*second operant of the operation*/
u8  global_u8Operator = '+'; /*contain the operation type*/
int main(void)
{
	u8 global_u8TempOperator = '+';    /* Helper temp value */
	
	u8 loc_u8Ptr[] = "Result : ";      /* For Compiler Issues */
	u8 loc_u8Ptr1[] = "       Welcome       "; /* For Compiler Issues */
	u8 loc_u8Ptr2[] = "OP: ";           /* For Compiler Issues */
	
	CLCD_voidClcdInit();                /* Initialize the LCD */
	KPD_Init();                         /* Initialize the keypad */
	
	CLCD_void8bitSendString(loc_u8Ptr1); /* Display welcome message */
	_delay_ms(2000);                     /* Delay for 2 seconds */
	
	CLCD_voidSend8bitCommand(_LCD_CLEAR_DISPLAY_); /* Clear the LCD */
	CLCD_void8bitSetCursorPosition(2,1);          /* Set cursor position */
	CLCD_void8bitSendString(loc_u8Ptr2);          /* Display "OP: " */
	
	while(1)
	{
		value_u8 = KPD_u8GetPressed();  /* Get the pressed key from the keypad */
		if(value_u8 != NOTPRESSED)      /* Check if a key is pressed */
		{
			if(value_u8 <= '9' && value_u8 >= '0') /* Check if the pressed key is a digit */
			{
				CLCD_void8bitSendData(value_u8); /* Display the pressed digit */
				global_f32FirstOperant = global_f32FirstOperant * 10 + (value_u8 - '0'); /* Update the first operand */
			}
			if((value_u8 == '+') || (value_u8 == '-') || (value_u8 == '*') || (value_u8 == '/')) /* Check if the pressed key is an operator */
			{
				CLCD_void8bitSendData(value_u8); /* Display the pressed operator */
				global_u8Operator = value_u8;    /* Update the global operator */
				global_f32SecondOperant = global_f32FirstOperant; /* Store the first operand */
				global_f32FirstOperant = 0; /* Reset the first operand */
				global_u8TempOperator = global_u8Operator; /* Store the operator temporarily */
			}
			if(value_u8 == '?') /* Check if the pressed key is '?' */
			{
				CLCD_voidSend8bitCommand(_LCD_CLEAR_DISPLAY_); /* Clear the LCD */
				global_f32FirstOperant = 0; /* Reset the operands */
				global_f32SecondOperant = 0;
				global_u8Operator = '+'; /* Reset the operator */
				CLCD_void8bitSetCursorPosition(2,1); /* Set cursor position */
				CLCD_void8bitSendString(loc_u8Ptr2); /* Display "OP: " */
			}
			if(value_u8 == '=') /* Check if the pressed key is '=' */
			{
				CLCD_void8bitSetCursorPosition(4,1); /* Set cursor position */
				CLCD_void8bitSendString(loc_u8Ptr); /* Display "Result: " */
				switch(global_u8TempOperator) /* Perform arithmetic operation based on the stored operator */
				{
					case '+' :
					CLCD_voidSendFloat((f32)global_f32FirstOperant + global_f32SecondOperant); /* Addition */
					break;
					case '-' :
					CLCD_voidSendFloat(-global_f32FirstOperant + (f32)global_f32SecondOperant); /* Subtraction */
					break;
					case '*' :
					CLCD_voidSendFloat((f32)global_f32FirstOperant * global_f32SecondOperant); /* Multiplication */
					break;
					case '/' :
					CLCD_voidSendFloat((f32)global_f32SecondOperant / global_f32FirstOperant ); /* Division */
					break;
				}
				
			}
			
		}
		
	}
}


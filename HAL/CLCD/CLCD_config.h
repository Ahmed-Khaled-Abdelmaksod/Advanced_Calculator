/*
 * CLCD_config.h
 *
 * Created: 23/03/2024 10:54:00 م
 *  Author: Ahmed Khaled
 */ 


#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_
/*
	use 8bit mode to neuronetix project
	there are 2 options :
	- CLCD_8BIT_MODE
	- CLCD_4BIT_MODE
*/
#define CLCD_MODE_SELECTION CLCD_8BIT_MODE


/*
	choose the LCD port:
	- CLCD_PORTA
	- CLCD_PORTB
	- CLCD_PORTC
	- CLCD_PORTD
	
	note : 
	if 8bit mode selected then RS ,RW ,EN BITs won't be in the same port of clcd
	if 8bit mode selected then RS ,RW ,EN BITs will be in the same port of clcd
	
	position of RS, EN bits  at 8bit mode :
	RS ->  PORTB PIN 0
	EN ->  PORTB PIN 1
	
*/

#define CLCD_PORT_SELECTION CLCD_PORTA

/*
	choose the nibble position 
	- CLCD_HIGHER_NIBBLE
	- CLCD_LOWER_NIBBLE
*/
#define CLCD_NIBBLE_POSITION CLCD_LOWER_NIBBLE



#endif /* CLCD_CONFIG_H_ */
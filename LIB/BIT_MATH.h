/*
* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< BIT MATH file >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * @author : Ahmed Khaled Abdelmaksod Ebrahim
 * @layer  : libraries
 * @brief  : contains helpful macrofunctions to bitwise operations
 */
#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_
/*
	@brief : used to set a specified bit inside a port
*/
#define SET_BIT(PORT,PIN)      PORT |= (1<<PIN)


/*
	@brief : used to clear a specified bit inside a port
*/
#define CLEAR_BIT(PORT, PIN)    (PORT &= ~(1 << (PIN)))


/*
	@brief : used to toggle a specified bit inside a port
*/
#define TOGGLE_BIT(PORT,PIN)   (PORT = PORT ^ (1<<PIN))

/*
	@brief : used to get a specified bit inside a port
*/
#define GET_BIT(PORT,PIN)      (((PORT >> PIN) & 0x01))

#endif

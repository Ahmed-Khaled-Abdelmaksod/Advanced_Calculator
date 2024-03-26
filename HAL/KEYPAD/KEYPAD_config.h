/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    KEYPAD_config.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Ahmed Khaled Abdelmaksod
 *  Layer  : HAL
 *  SWC    : KPD
 *
 */

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_


#define KPD_ROW_INIT  PIN0
#define KPD_ROW_END   PIN3

#define KPD_COL_INIT  PIN4
#define KPD_COL_END   PIN7

                         /* C0   C1  C2  C3  */
u8 KPD_u8Buttons[4][4] = { {'7','8','9','/'}, /* Row0 */
						   {'4','5','6','*'}, /* Row1 */
						   {'1','2','3','-'}, /* Row2 */
						   {'?','0','=','+'}  /* Row3 */};


/*
 	 Options:-

 	 	 1-PORTA_INDEX
 	 	 2-PORTB_INDEX
 	 	 3-PORTC_INDEX
 	 	 4-PORTD_INDEX

 */

#define KPD_PORT  PORTC_INDEX

/*
 Options :-

 	 1-PIN0
 	 2-PIN1
 	 3-PIN2
 	 4-PIN3
 	 5-PIN4
 	 6-PIN5
 	 7-PIN6
 	 8-PIN7

 * */

#define KPD_R0    PIN0
#define KPD_R1    PIN1
#define KPD_R2    PIN2
#define KPD_R3    PIN3

#define KPD_C0    PIN4
#define KPD_C1    PIN5
#define KPD_C2    PIN6
#define KPD_C3    PIN7

#endif /* KPD_CONFIG_H_ */
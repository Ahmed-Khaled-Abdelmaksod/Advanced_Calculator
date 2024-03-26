/*
 * CLCD_interface.h
 *
 * Created: 23/03/2024 10:53:38 م
 *  Author: Ahmed Khaled
 */ 


#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

/************************************************************************/
/*                include section                                                       */
/************************************************************************/
#include"CLCD_config.h"

/************************************************************************/
/*                        definitions section                           */
/************************************************************************/


// commands
#define _LCD_CLEAR_DISPLAY_                         (u8)0x01
#define _LCD_RETURN_HOME_                           (u8)0x02
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF               (u8)0x06
#define _LCD_ENTRY_MODE_INC_SHIFT_ON                (u8)0x07
#define _LCD_ENTRY_MODE_DEC_SHIFT_OFF               (u8)0x04
#define _LCD_ENTRY_MODE_DEC_SHIFT_ON                (u8)0x05
#define _LCD_CURSOR_SHIFT_RIGHT                     (u8)0x14
#define _LCD_CURSOR_SHIFT_LEFT                      (u8)0x10
#define _LCD_DISPLAY_SHIFT_LEFT                     (u8)0x18
#define _LCD_DISPLAY_SHIFT_RIGHT                    (u8)0x1C
#define _LCD_4BIT_MODE_2LINE                        (u8)0x28
#define _LCD_8BIT_MODE_2LINE                        (u8)0x38
#define _LCD_DISPLAY_ON_CURSOR_OFF_UNDERLINE_OFF    (u8)0x0C
#define _LCD_DISPLAY_ON_CURSOR_OFF_UNDERLINE_ON     (u8)0x0D
#define _LCD_DISPLAY_ON_CURSOR_ON_UNDERLINE_OFF     (u8)0x0E
#define _LCD_DISPLAY_ON_CURSOR_ON_UNDERLINE_ON      (u8)0x0F
#define _LCD_DISPLAY_OFF_CURSOR_OFF_UNDERLINE_OFF   (u8)0x08
#define _LCD_START_CGRAM_ADR                        (u8)0x40
#define _LCD_START_DDRAM_ADR                        (u8)0x80




/************************************************************************/
/*                        interfaces  section                           */
/************************************************************************/

void CLCD_voidClcdInit();
void CLCD_void8bitSendData(u8 loc_u8Data);
void CLCD_voidSend8bitCommand(u8 loc_u8Command);
void CLCD_void8bitSetCursorPosition(u8 loc_u8Row,u8 loc_u8Column);
void CLCD_void8bitSendString(u8* loc_ptrString);

void CLCD_voidSendFloat(f64 loc_f64Data);
void CLCD_voidSendNum(u32 loc_u32Num);
#endif /* CLCD_INTERFACE_H_ */
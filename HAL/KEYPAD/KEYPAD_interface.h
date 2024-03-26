/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    KPD_interface.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Ahmed Khaled Abdelmaksod
 *  Layer  : HAL
 *  SWC    : KPD
 *
 */

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

#include"../../LIB/STD_TYPES.h"

#define NOTPRESSED 0xff

void KPD_Init(void);
u8   KPD_u8GetPressed( void );

#endif /* KPD_INTERFACE_H_ */
/*
 * Buttons.h
 *
 * Created: 7/23/2022 8:26:25 PM
 *  Author: Electric_Water_Heater_Team
 */ 


#ifndef BUTTONS_H_
#define BUTTONS_H_

/****************************************_INCLUDES_***********************************************/
#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "BitMaths.h"
#include "StdTypes.h"
#include "ButtonsCfg.h"
/****************************************_MACROS_***********************************************/
#define PRESSED     1
#define NOT_PRESSED 0
/****************************************_PROTOTYPES_***********************************************/
void H_ButtonsInit(void);
void H_Buttons_OnOff_ExtInt(void);

u8 H_Buttons_UpPressed(void);
u8 H_Buttons_DownPressed(void);


#endif /* BUTTONS_H_ */
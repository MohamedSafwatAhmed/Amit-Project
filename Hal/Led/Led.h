/*
 * Led.h
 *
 * Created: 7/23/2022 8:13:04 PM
 *  Author: Electric_Water_Heater_Team
 */ 


#ifndef LED_H_
#define LED_H_

/****************************************_INCLUDES_***********************************************/
#include <avr/io.h>
#include "BitMaths.h"
#include "LedCfg.h"
/****************************************_MACROS_***********************************************/
void H_Led_Init(void);
void H_Led_On(void);
void H_Led_Off(void);


#endif /* LED_H_ */
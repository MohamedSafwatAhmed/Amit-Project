/*
 * Timer.h
 *
 * Created: 7/23/2022 8:51:41 PM
 *  Author: Electric_Water_Heater_Team
 */ 


#ifndef TIMER_H_
#define TIMER_H_

/****************************************_INCLUDES_***********************************************/
#include <avr/io.h>
#include <avr/interrupt.h>
#include "StdTypes.h"
#include "BitMaths.h"
/****************************************_PROTOTYPES_***********************************************/
void M_Timer0_Init(void);
void M_Timer1_Init(void);
void M_Timer1_IntDisable(void);
void M_Timer1_IntEnable(void);


#endif /* TIMER_H_ */
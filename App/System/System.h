/*
 * System.h
 *
 * Created: 7/23/2022 9:08:49 PM
 *  Author: Electric_Water_Heater_Team
 */ 


#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <avr/io.h>
#include "SystemCfg.h"
#include "StdTypes.h"
#include "BitMaths.h"
#include "Adc.h"
#include "Buttons.h"
#include "HeatCoolElements.h"
#include "Led.h"
#include "Ssd.h"
#include "Timer.h"
#include "Eeprom.h"
#define F_CPU 1000000UL
#include <util/delay.h>
/***********************************_MACROS_*******************************/
#define OFF     0
#define ON      1
#define SETTING 2

/***********************************_PROTOTYPES_*******************************/
void A_System_Init(void);
void A_System_OnState(void);
void A_System_OffState(void);
void A_System_SetState(void);
void A_System_ChangeTemp(void);
void A_System_AddNewTemp(u16 * arr , u16 new_val);
u16  A_System_CalcAvgTemp(u16 * arr);
void A_System_TempArrInit(void);
void A_System_Sleep(void);

/***********************************_Variables_*******************************/
u8 App_u8_CurrState;

u16 App_u16_TempArr[NUM_OF_TEMP_MEASURES];
u16 App_u16_DesiredTemp;
u16 App_u16_ActualTemp;
u16 App_u16_AvgTemp;

u8 App_u8_TempMeasureF;
u8 App_u8_TempMeasureCounter;
u8 App_u8_SettingCounter;

u16 App_u16_ToggleF;
u8  App_u8_ArrCounter;



#endif /* SYSTEM_H_ */
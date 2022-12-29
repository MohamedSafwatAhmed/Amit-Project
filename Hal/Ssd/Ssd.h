/*
 * Ssd.h
 *
 * Created: 7/23/2022 8:38:04 PM
 *  Author: Electric_Water_Heater_Team
 */ 


#ifndef SSD_H_
#define SSD_H_
/****************************************_INCLUDES_***********************************************/
#include <avr/io.h>
#include "BitMaths.h"
#define F_CPU 1000000UL
#include <util/delay.h>
#include "SsdCfg.h"
#include "StdTypes.h"
/****************************************_MACROS_***********************************************/
#define DISP1 1
#define DISP2 2
/****************************************_PROTOTYPES_***********************************************/
void H_Ssd_Init(void);
void H_Ssd_Send(u16);
void H_Ssd_Enable(u8);
void H_Ssd_Disable(void);
void H_Ssd_TurnOff(void);
void H_Ssd_Write(u16);



#endif /* SSD_H_ */
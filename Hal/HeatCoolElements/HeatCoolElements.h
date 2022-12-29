/*
 * HeatCoolElements.h
 *
 * Created: 7/23/2022 8:19:26 PM
 *  Author: Electric_Water_Heater_Team
 */ 


#ifndef HEATCOOLELEMENTS_H_
#define HEATCOOLELEMENTS_H_


/****************************************_INCLUDES_***********************************************/
#include <avr/io.h>
#include "BitMaths.h"
#include "HeatCoolElementsCfg.h"
/****************************************_MACROS_***********************************************/
void H_HeatInit(void);
void H_HeatStart(void);
void H_HeatStop(void);

void H_CoolInit(void);
void H_CoolStart(void);
void H_CoolStop(void);

#endif /* HEATCOOLELEMENTS_H_ */
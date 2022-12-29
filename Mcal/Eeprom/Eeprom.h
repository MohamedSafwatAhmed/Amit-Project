/*
 * Eeprom.h
 *
 * Created: 7/23/2022 8:51:05 PM
 *  Author: Electric_Water_Heater_Team
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

/****************************************_INCLUDES_***********************************************/
#include <avr/io.h>
#include "StdTypes.h"
#include "BitMaths.h"
/****************************************_PROTOTYPES_***********************************************/

void M_Eeprom_Write(const u16, u8);
u8   M_Eeprom_Read(const u16);


#endif /* EEPROM_H_ */
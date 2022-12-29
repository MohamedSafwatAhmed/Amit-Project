/*
 * Adc.h
 *
 * Created: 7/23/2022 8:50:37 PM
 *  Author: Electric_Water_Heater_Team
 */ 


#ifndef ADC_H_
#define ADC_H_

/****************************************_INCLUDES_***********************************************/
#include <avr/io.h>
#include "StdTypes.h"
#include "BitMaths.h"

/****************************************_PROTOTYPES_***********************************************/
void M_Adc_Init(void);
u16  M_Adc_Read(void);


#endif /* ADC_H_ */
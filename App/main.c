/*
 * Electric_Heater.c
 *
 * Created: 7/23/2022 8:08:17 PM
 * Author : Electric_Water_Heater_Team
 */ 

#include <avr/io.h>
#include "StdTypes.h"
#include "BitMaths.h"
#include "System.h"
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
	
	A_System_Init();
	
	while(1)
	{
		switch (App_u8_CurrState)
		{
			case ON:
			{
				A_System_OnState();
				break;
			}
			case OFF:
			{
				A_System_OffState();
				break;
			}
			case SETTING:
			{
				A_System_SetState();
				break;
			}
			default :
			{
				break;
			}
		}
	}
	
	return (0);
}


/******ON/OFF Button ISR********/

ISR(INT2_vect)
{
	if(App_u8_CurrState == OFF)
	{
		App_u8_CurrState = ON;
		App_u16_DesiredTemp = M_Eeprom_Read(0x0000);
	}
	else if (App_u8_CurrState==ON || App_u8_CurrState==SETTING)
	{
		App_u8_CurrState = OFF;
	}
}

/****TIMER1_ISR (A) : It triggers the ISR every 100ms. So, it makes the temperature
measure flag equals one to enable the ADC to do the work.*****/

ISR(TIMER1_COMPA_vect)
{
	App_u8_TempMeasureF = 1;
}

/*****TIMER1_ISR (B) : It triggers the ISR every 1 second. So, it toggles the
toggle flag for the LED and the Seven Segment. and counts to keep it in
ON_STATE if nothing is pressed during in ON or SETTING modes for 5 secs.
**********/

ISR(TIMER0_COMP_vect)
{
	if ((App_u8_CurrState==SETTING) || (App_u8_CurrState==ON))
	{
		App_u8_SettingCounter++;
		if(App_u8_SettingCounter % 4 == 0)
		{
			App_u16_ToggleF ^= 1;
		}
		if (App_u8_SettingCounter > 20)
		{
			App_u8_CurrState = ON;
		}
	}
}
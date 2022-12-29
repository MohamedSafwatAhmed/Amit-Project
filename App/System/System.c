/*
 * System.c
 *
 * Created: 7/23/2022 9:08:58 PM
 *  Author: Electric_Water_Heater_Team
 */ 
#include "System.h"

void A_System_Init(void)
{
	// Modules initialization
	M_Adc_Init();
	H_ButtonsInit();
	H_CoolInit();
	H_HeatInit();
	H_Led_Init();
	H_Ssd_Init();
	M_Timer0_Init();
	M_Timer1_Init();
	M_Timer1_IntEnable();
	
	// ON_OFF_flag is in OFF mode initially
	App_u8_CurrState = OFF;
	
	// setting initial temp. and fill array
	if(M_Eeprom_Read(0x0000) != 0xFF)
	{
		App_u16_DesiredTemp = M_Eeprom_Read(0x0000);
	}
	else
	{
		App_u16_DesiredTemp = INIT_DESIRED_TEMP;
	}
	
	A_System_TempArrInit();
	
	// Save desired temp in EEPROM
	// which is the INIT_DESIRED_TEMP.
	M_Eeprom_Write(0x0000,(u8) App_u16_DesiredTemp);
	
}
/*---------------------------------------------------------------------*/

void A_System_OffState(void)
{
	H_Ssd_TurnOff();
	H_Led_Off();
	H_HeatStop();
	H_CoolStop();

}

void A_System_OnState(void)
{
	// if 100ms elapsed and flag is triggered
	// measure temperature from the sensor
	// add it to array and get the average
	
	if (App_u8_TempMeasureF == 1)
	{
		App_u16_ActualTemp = (M_Adc_Read()*0.5);
		A_System_AddNewTemp(App_u16_TempArr , App_u16_ActualTemp);
		App_u16_AvgTemp = A_System_CalcAvgTemp(App_u16_TempArr);
		App_u8_TempMeasureF = 0;
	}
	
	H_Ssd_Write(App_u16_ActualTemp);
	
	// turn cooler or heater ON and OFF depending on
	// the average temperature measured from the array.
	
	A_System_ChangeTemp();
	
	// Check if UP or DOWN buttons are pressed to
	// switch to the SETTING_MODE
	
	if(H_Buttons_UpPressed() == PRESSED || H_Buttons_DownPressed() == PRESSED)
	{

		H_Ssd_Disable();
		App_u8_SettingCounter = 0;
		App_u8_CurrState = SETTING;
		
	}
}


void A_System_SetState(void)
{
	H_HeatStop();
	H_CoolStop();
	H_Led_Off();
	
	// to toggle the seven segment
	// while writing the desired temperature
	
	if(App_u16_ToggleF == 1)
	{
		H_Ssd_Write(App_u16_DesiredTemp);
	}
	else
	{
		H_Ssd_TurnOff();
	}
	
	// if UP or DOWN pressed, change the desired temp
	// as long as it's still in range
	
	if((H_Buttons_UpPressed() == PRESSED) && (App_u16_DesiredTemp < MAX_TEMP))
	{
		App_u16_DesiredTemp = App_u16_DesiredTemp + 5;
		App_u8_SettingCounter = 0;
		H_Ssd_Write(App_u16_DesiredTemp);
	}
	else if ((H_Buttons_DownPressed() == PRESSED) && (App_u16_DesiredTemp > MIN_TEMP))
	{
		App_u16_DesiredTemp = App_u16_DesiredTemp - 5;
		App_u8_SettingCounter = 0;
		H_Ssd_Write(App_u16_DesiredTemp);
	}
	
	M_Eeprom_Write(0x0000,App_u16_DesiredTemp);
	
}

void A_System_ChangeTemp(void)
{
	if( (App_u16_DesiredTemp < App_u16_AvgTemp + MARGIN_TEMP) && (App_u16_DesiredTemp > App_u16_AvgTemp - MARGIN_TEMP) )
	{
		// Actual Temperature equals Desired Temperature
		// No need for Heating or Cooling
		H_HeatStop();
		H_CoolStop();
		H_Led_Off();
	}
	else if(App_u16_DesiredTemp < App_u16_AvgTemp + MARGIN_TEMP)
	{
		// Actual Temperature is Larger
		// we need the Cooling element
		
		H_HeatStop();
		H_CoolStart();
		H_Led_On();
	}
	else if (App_u16_DesiredTemp > App_u16_AvgTemp - MARGIN_TEMP)
	{
		// Actual Temperature is Smaller
		// we need the Heating element
		
		H_HeatStart();
		H_CoolStop();
		if (App_u16_ToggleF == 1)
		{
			H_Led_On();
		}
		else 
		{
			H_Led_Off();
		}
	}
}

void A_System_TempArrInit(void)
{
	u16 Local_u16_FirstTemp = M_Adc_Read()*0.5;
	
	for (u8 i = 0; i<NUM_OF_TEMP_MEASURES; i++)
	{
		App_u16_TempArr[i]= Local_u16_FirstTemp;
	}
	
	App_u16_AvgTemp = A_System_CalcAvgTemp(App_u16_TempArr);
	App_u8_ArrCounter = 0;
}

void A_System_AddNewTemp(u16 * arr , u16 new_val)
{
	arr[App_u8_ArrCounter] = new_val;
	App_u8_ArrCounter++;
	
	if (App_u8_ArrCounter == 10)
	{
		App_u8_ArrCounter = 0;
	}
}

u16 A_System_CalcAvgTemp(u16 * arr)
{
	u16 Local_u16_Sum = 0;
	u16 Local_u16_Avg;
	
	for(u8 i=0; i<NUM_OF_TEMP_MEASURES; i++)
	{
		Local_u16_Sum = Local_u16_Sum + arr[i];
	}
	Local_u16_Avg = (u16) Local_u16_Sum / NUM_OF_TEMP_MEASURES;
	return Local_u16_Avg;
}

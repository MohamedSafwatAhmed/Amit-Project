/*
 * Ssd.c
 *
 * Created: 7/23/2022 8:38:13 PM
 *  Author: Electric_Water_Heater_Team
 */ 
#include "Ssd.h"

u8 Ssd_u8_Arr[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F}; //Array Initialization

void H_Ssd_Init(void)
{
	// setting Seven Segment Pins as output pins
	SSD_PORT_DIR = 0xFF;
	SetBit(SSD_ENABLE_PORT_DIR,SSD1_ENABLE_PIN);
	SetBit(SSD_ENABLE_PORT_DIR,SSD2_ENABLE_PIN);
	
	// Seven Segment initially OFF
	H_Ssd_Disable();
	
}

void H_Ssd_Send(u16 Local_u16_Counter)
{
	SSD_DATA = Ssd_u8_Arr[Local_u16_Counter];
}


void H_Ssd_Enable(u8 Local_u8_Disp)
{
	if(Local_u8_Disp == 1)
	{
		SetBit(SSD_ENABLE_PORT,SSD1_ENABLE_PIN);
		ClrBit(SSD_ENABLE_PORT,SSD2_ENABLE_PIN);
	}
	else if (Local_u8_Disp == 2)
	{
		SetBit(SSD_ENABLE_PORT,SSD2_ENABLE_PIN);
		ClrBit(SSD_ENABLE_PORT,SSD1_ENABLE_PIN);
	}
}

void H_Ssd_Disable(void)
{
	ClrBit(SSD_ENABLE_PORT,SSD1_ENABLE_PIN);
	ClrBit(SSD_ENABLE_PORT,SSD2_ENABLE_PIN);
}

void H_Ssd_TurnOff(void)
{
	SSD_DATA = 0x00;
}

void H_Ssd_Write(u16 Local_u16_Num)
{
	u8 Local_u8_Units;
	u8 Local_u8_Tens;
	
	Local_u8_Units = Local_u16_Num % 10;
	Local_u8_Tens  = (int) Local_u16_Num / 10;
	
	H_Ssd_Enable(DISP1);
	H_Ssd_Send(Local_u8_Units);
	_delay_ms(5);
	
	H_Ssd_Enable(DISP2);
	H_Ssd_Send(Local_u8_Tens);
	_delay_ms(5);
}
/*
 * Eeprom.c
 *
 * Created: 7/23/2022 8:51:23 PM
 *  Author: Electric_Water_Heater_Team
 */ 
#include "Eeprom.h"

u8 M_Eeprom_Read(const u16 Local_u16_Address)
{
	// Setup Address Register
	EEARL = (unsigned char)Local_u16_Address;
	EEARH = (unsigned char)(Local_u16_Address>>8);
	
	// Start Reading
	SetBit(EECR,EERE);
	
	// Return Data
	return EEDR;
}


void M_Eeprom_Write(const u16 Local_u16_Address, u8 Local_u8_Data)
{
	u8 INT_EN=0;
	
	// Setup Address Register
	EEARL = (unsigned char)Local_u16_Address;
	EEARH = (unsigned char)(Local_u16_Address>>8);
	
	// Put Data in Data Register
	EEDR = Local_u8_Data;
	
	// Disable Interrupts to work fine
	if(((SREG&(1<<7))>>7)==1){
		INT_EN = 1;
		ClrBit(SREG,7);
	}
	
	// Start Writing
	
	SetBit(EECR,EEMWE);
	SetBit(EECR,EEWE);
	while(((EECR&(1<<EEWE))>>EEWE)==1);
	
	// Back
	if (INT_EN==1)
	{
		SetBit(SREG,7);
	}
	
}
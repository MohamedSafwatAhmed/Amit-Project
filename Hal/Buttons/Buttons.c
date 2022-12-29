/*
 * Buttons.c
 *
 * Created: 7/23/2022 8:26:35 PM
 *  Author: Electric_Water_Heater_Team
 */ 
#include "Buttons.h"

void H_ButtonsInit(void)
{
	// Setting the pins as INPUT pins
	ClrBit(B_PORT_DIR,ON_OFF_PIN);
	ClrBit(B_PORT_DIR,UP_PIN);
	ClrBit(B_PORT_DIR,DOWN_PIN);
	
	// Enable internal Pull-Up Resistor
	SetBit(B_PORT,ON_OFF_PIN);
	SetBit(B_PORT,UP_PIN);
	SetBit(B_PORT,DOWN_PIN);
	
	
	// This Following Section is for the external interrupt
	// assigned to the ON/OFF Button.
	
	// Enable Global Interrupt bit
	sei();
	// Trigger with Rising Edge
	SetBit(MCUCSR,ISC2);
	// Enable INT2 (External Interrupt)
	SetBit(GICR,INT2);
}



u8 H_Buttons_UpPressed(void)
{
	// Check if pressed for the first time
	if(!(ReadBit(PINB,UP_PIN)))
	{
		// wait for 50 ms to make sure it's pressed (DEBOUNCING solution)
		_delay_ms(DEBOUNCE_INTERVAL);
		
		// check one more time
		if (!(ReadBit(PINB,UP_PIN)))
		{
			return PRESSED;
		}
		else return NOT_PRESSED;
	}
	else return NOT_PRESSED;
}



u8 H_Buttons_DownPressed(void)
{
	// Check if pressed for the first time
	if(!(ReadBit(PINB,DOWN_PIN)))
	{
		// wait for 50 ms to make sure it's pressed (DEBOUNCING solution)
		_delay_ms(DEBOUNCE_INTERVAL);
		
		// check one more time
		if (!(ReadBit(PINB,DOWN_PIN)))
		{
			return PRESSED;
		}
		else return NOT_PRESSED;
	}
	else return NOT_PRESSED;
}
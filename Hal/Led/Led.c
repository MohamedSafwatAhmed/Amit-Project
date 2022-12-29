/*
 * Led.c
 *
 * Created: 7/23/2022 8:13:13 PM
 *  Author: Electric_Water_Heater_Team
 */ 
#include "LED.h"

void H_Led_Init(void)
{
	// PIN 0 in the port is an output pin
	// the LED pin is initially off
	SetBit(LED_PORT_DIR,LED_PIN);
	ClrBit(LED_PORT,LED_PIN);
}

void H_Led_On(void)
{
	SetBit(LED_PORT,LED_PIN);
}

void H_Led_Off(void)
{
	ClrBit(LED_PORT,LED_PIN);
}
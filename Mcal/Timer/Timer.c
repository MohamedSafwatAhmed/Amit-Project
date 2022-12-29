/*
 * Timer.c
 *
 * Created: 7/23/2022 8:51:32 PM
 *  Author: Electric_Water_Heater_Team
 */ 
#include "Timer.h"

void M_Timer1_Init(void)
{
	// trigger an interrupt every One millisecond
	// Select CTC Mode
	SetBit(TCCR1B,WGM12);
	// Load Value in OCR1A
	OCR1AH = 0b00000000;
	OCR1AL = 0b01100010;
	// Select Clock PRESCALER (F_CPU / 1024)
	SetBit(TCCR1B,CS10);
	ClrBit(TCCR1B,CS11);
	SetBit(TCCR1B,CS12);
	// Enable Global Interrupt bit
	sei();
}

void M_Timer0_Init(void)
{
	
	// choose mode
	SetBit(TCCR0,WGM01);
	
	// Load Value in OCR0
	OCR0 = 250;
	
	// Choose PRESCALER
	SetBit(TCCR0,CS00);
	SetBit(TCCR0,CS02);
	
	// Enable Timer INT
	sei();
	SetBit(TIMSK,OCIE0);
	
}

void M_Timer1_IntDisable(void)
{
	
	// Disable Interrupts when Comparing with values A and B
	SetBit(TIMSK,OCIE1A);
	
}

void M_Timer1_IntEnable(void)
{
	
	// Enable Interrupts when Comparing with values A and B
	SetBit(TIMSK,OCIE1A);
	
}
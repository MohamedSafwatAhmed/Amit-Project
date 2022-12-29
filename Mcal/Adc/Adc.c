/*
 * Adc.c
 *
 * Created: 7/23/2022 8:50:44 PM
 *  Author: Electric_Water_Heater_Team
 */ 
#include "Adc.h"

void M_Adc_Init(void)
{
	
	// Choosing reference voltage option.
	// the AVCC pin with a capacitor at the AREF pin.
	SetBit(ADMUX,REFS0);
	
	// Choosing Channel One (Single Ended In.) at A0 pin.
	ClrBit(ADMUX,MUX0);
	ClrBit(ADMUX,MUX1);
	ClrBit(ADMUX,MUX2);
	ClrBit(ADMUX,MUX3);
	ClrBit(ADMUX,MUX4);
	
	// Choosing the Data to be Right Adjusted in the Data Reg.
	ClrBit(ADMUX,ADLAR);
	
	// Choosing PRESCALER for the ADC clock.
	// the following is choosing (2) as a PRESCALER.
	SetBit(ADCSRA,ADPS0);
	ClrBit(ADCSRA,ADPS1);
	ClrBit(ADCSRA,ADPS2);
	
	// Enable the ADC
	SetBit(ADCSRA,ADEN);
	
}



u16 M_Adc_Read(void)
{
	
	u16 data;
	
	// Start Conversion
	SetBit(ADCSRA,ADSC);
	
	// Wait for flag to be set.
	// Indication of finished conversion
	while(IsBitClr(ADCSRA,ADIF));
	
	// Read Data from the ADC Data Register
	// Read the Low register first!
	data = ADCL;
	data |= (ADCH<<8);
	
	// Clear Flag (As we are not using the interrupt)
	// It won't be cleared automatically!
	SetBit(ADCSRA,ADIF);
	
	return data;
}
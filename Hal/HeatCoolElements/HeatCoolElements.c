/*
 * HeatCoolElements.c
 *
 * Created: 7/23/2022 8:19:36 PM
 *  Author: Electric_Water_Heater_Team
 */ 
#include "HeatCoolElements.h"

void H_HeatInit(void){
	SetBit(HEAT_PORT_DIR,HEAT_PIN);
}

void H_CoolInit(void){
	SetBit(COOL_PORT_DIR,COOL_PIN);
}


void H_HeatStart(void){
	SetBit(HEAT_PORT,HEAT_PIN);
}

void H_CoolStart(void){
	SetBit(COOL_PORT,COOL_PIN);
}

void H_HeatStop(void){
	ClrBit(HEAT_PORT,HEAT_PIN);
}

void H_CoolStop(void){
	ClrBit(COOL_PORT,COOL_PIN);
}
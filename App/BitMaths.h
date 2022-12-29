/*
 * BitMaths.h
 *
 * Created: 7/23/2022 8:09:16 PM
 *  Author: Electric_Water_Heater_Team
 */ 


#ifndef BITMATHS_H_
#define BITMATHS_H_

/*************************************************************_MACROS_**********************************************************/
#define SetBit(reg,bit) reg=reg|(1<<bit) 
#define ClrBit(reg,bit) reg=reg&(~(1<<bit))
#define TogBit(reg,bit) reg=reg^(1<<bit)
#define ReadBit(reg,bit) reg&(1<<bit)
#define IsBitSet(reg,bit) reg&(1<<bit)>>bit
#define IsBitClr(reg,bit) !(reg&(1<<bit)>>bit)




#endif /* BITMATHS_H_ */
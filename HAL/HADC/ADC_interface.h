/*
 * ADC_interface.h
 *
 *  Created on: ٢٢‏/٠٨‏/٢٠٢٦
 *      Author: Omar
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#include "../../MCAL/MADC/MADC_register.h"


#define ADC_CHANNEL1   0
#define ADC_CHANNEL2   1
#define ADC_CHANNEL3   2
#define ADC_CHANNEL4   3
#define ADC_CHANNEL5   4
#define ADC_CHANNEL6   5
#define ADC_CHANNEL7   6
#define ADC_CHANNEL8   7


extern u8 ARR_CHANNAL[];

void (*HADC_CAB_INT)(void);

void HADC_Init();

u16 HADC_u16ReadDigitalVal(u8 Copy_u8chanaal);
u16 HADC_u16GetReadDigitalVal(u8 Copy_u8chanaal);
void HADC_chooseStartConversionMode(u8 Copy_u8ConversionMode);

void HADC_vidEnableInterInterrupt();
void HADC_vidDisableInterInterrupt();

void HADC_vidEnable();
void HADC_vidDisable();

void HADC_vidClrFlag();




#endif /* MCAL_ADC_ADC_INTERFACE_H_ */

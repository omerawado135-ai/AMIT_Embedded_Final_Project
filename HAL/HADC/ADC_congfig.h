/*
 * ADC_congfig.h
 *
 *  Created on: ٢٢‏/٠٨‏/٢٠٢٦
 *      Author: Omar
 */

#ifndef MCAL_ADC_ADC_CONGFIG_H_
#define MCAL_ADC_ADC_CONGFIG_H_


#define ADC_AREF       0
#define ADC_AVCC       1
#define ADC_INTERNAL   2
#define ADC_VOLT   ADC_AVCC

#define FREE_RUN_MODE      0
#define ANALOG_COMPARATOR  1
#define EXT_INTURREPT      2
#define CONVERSION_MODE  FREE_RUN_MODE

#define ADC_DIVISION_FACTOR_2        (u8)0x01
#define ADC_DIVISION_FACTOR_4        (u8)0x02
#define ADC_DIVISION_FACTOR_8        (u8)0x03
#define ADC_DIVISION_FACTOR_16       (u8)0x04
#define ADC_DIVISION_FACTOR_32       (u8)0x05
#define ADC_DIVISION_FACTOR_64       (u8)0x06
#define ADC_DIVISION_FACTOR_128      (u8)0x07

#define ADC_PRESCALER   ADC_DIVISION_FACTOR_128


/*---------CHANNEL CLEAR MASK-------*/

#define ADC_CLEAR_MASK       (u8)0xE0
#define ADC_PRESCALER_MASK   (u8)0xF8

/*---------EXTERN THE ARRAY OF THE CHANNAL------------*/

extern u8 ARR_CHANNAL[];

#endif /* MCAL_ADC_ADC_CONGFIG_H_ */

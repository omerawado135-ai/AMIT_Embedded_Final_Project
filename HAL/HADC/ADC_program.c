/*
 * ADC_program.c
 *
 *  Created on: ٢٢‏/٠٨‏/٢٠٢٦
 *      Author: Omar
 */
#include "../../utils/STD_TYPES.h"
#include "../../utils/bit_math.h"
#include "../../MCAL/MADC/MADC_register.h"
#include "ADC_interface.h"
#include "ADC_congfig.h"
#include <util/delay.h>


ISR(ADC_vector)
{
    HADC_CAB_INT();
}


void HADC_Init(void)
{
	#if ADC_VOLT == ADC_AREF
	CLR_BIT(ADMUX_REG, ADMUX_REFS1);
	CLR_BIT(ADMUX_REG, ADMUX_REFS0);
	#elif ADC_VOLT == ADC_AVCC
	CLR_BIT(ADMUX_REG, ADMUX_REFS1);
	SET_BIT(ADMUX_REG, ADMUX_REFS0);
	#elif ADC_VOLT == ADC_INTERNAL
	SET_BIT(ADMUX_REG, ADMUX_REFS1);
	SET_BIT(ADMUX_REG, ADMUX_REFS0);
	#endif

	CLR_BIT(ADMUX_REG, ADMUX_ADLAR);
	ADCSRA_REG = (ADCSRA_REG & ADC_PRESCALER_MASK) | ADC_PRESCALER;
	SET_BIT(ADCSRA_REG, ADCSRA_ADEN);
}



void HADC_chooseStartConversionMode(u8 Copy_u8ConversionMode)
{
#if CONVERSION_MODE==FREE_RUN_MODE
	CLR_BIT(SFIOR_REG,ADTS0);
	CLR_BIT(SFIOR_REG,ADTS1);
	CLR_BIT(SFIOR_REG,ADTS2);
#elif CONVERSION_MODE==ANALOG_COMPARATOR
	SET_BIT(SFIOR_REG,ADTS0);
	CLR_BIT(SFIOR_REG,ADTS1);
	CLR_BIT(SFIOR_REG,ADTS2);
#elif CONVERSION_MODE==EXT_INTURREPT
	CLR_BIT(SFIOR_REG,ADTS0);
	SET_BIT(SFIOR_REG,ADTS1);
	CLR_BIT(SFIOR_REG,ADTS2);
#endif

	SET_BIT(ADCSRA_REG,ADCSRA_ADSC);    // start conversion
}


void HADC_vidReadDigitalVal(u8 Copy_u8chanaal){
	ADMUX_REG &= ADC_CLEAR_MASK;
	ADMUX_REG |= Copy_u8chanaal;
	SET_BIT(ADCSRA_REG, ADCSRA_ADSC);	
}

u16 HADC_u16GetDigitalVal(void){
	u16 Res = 0;
	Res = ADCL_REG;
	Res |= ((u16)ADCH_REG << 8);
	return Res;
}
u16 HADC_u16GetReadDigitalVal(u8 Copy_u8chanaal)
{
	u16 Res = 0;
	ADMUX_REG &= ADC_CLEAR_MASK;
	ADMUX_REG |= Copy_u8chanaal;
	SET_BIT(ADCSRA_REG, ADCSRA_ADSC);
	while (GET_BIT(ADCSRA_REG, ADCSRA_ADSC));
	Res = ADCL_REG;
	Res |= ((u16)ADCH_REG << 8);
	return Res;
}
	
void HADC_vidEnableInterInterrupt()
{
	SET_BIT(SREG_REG,SREG_GIE);
	SET_BIT(ADCSRA_REG,ADCSRA_ADIE);
}
void HADC_vidDisableInterInterrupt()
{
	CLR_BIT(ADCSRA_REG,ADCSRA_ADIE);
}

void HADC_vidEnable()
{
	SET_BIT(ADCSRA_REG,ADCSRA_ADEN);
}
void HADC_vidDisable()
{
	CLR_BIT(ADCSRA_REG,ADCSRA_ADEN);

}

void HADC_vidClrFlag()
{
	SET_BIT(ADCSRA_REG,ADCSRA_ADIF);
}


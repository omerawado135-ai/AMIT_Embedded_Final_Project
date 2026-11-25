
#ifndef MCAL_ADC_ADC_REGISTER_H_
#define MCAL_ADC_ADC_REGISTER_H_



#define ISR(vector)  															\
	void vector(void)	__attribute__((signal,used,externally_visible));		    \
	void vector(void)

#define ADC_vector     __vector_16



#define ADMUX_REG   *((volatile u8 *)0x27)
#define ADCSRA_REG  *((volatile u8 *)0x26)
#define ADCH_REG    *((volatile u8 *)0x25)
#define ADCL_REG    *((volatile u8 *)0x24)
#define SFIOR_REG   *((volatile u8 *)0x50)
#define SREG_REG    *((volatile u8 *)0x5F)


/*-------ADMUX_REG--------*/
#define ADMUX_MUX0      (u8)0
#define ADMUX_MUX1      (u8)1
#define ADMUX_MUX2      (u8)2
#define ADMUX_MUX3      (u8)3
#define ADMUX_MUX4      (u8)4
#define ADMUX_ADLAR     (u8)5
#define ADMUX_REFS0     (u8)6
#define ADMUX_REFS1     (u8)7


/*------ADCSRA-------*/
#define ADCSRA_ADEN     (u8)7
#define ADCSRA_ADSC     (u8)6
#define ADCSRA_ADATE    (u8)5
#define ADCSRA_ADIF     (u8)4
#define ADCSRA_ADIE     (u8)3
#define ADCSRA_ADPS2    (u8)2
#define ADCSRA_ADPS1    (u8)1
#define ADCSRA_ADPS0    (u8)0

/*----- SFIOR ---------*/
#define ADTS2            (u8)7
#define ADTS1            (u8)6
#define ADTS0            (u8)5

/*-------SREG-------*/
#define SREG_GIE        (u8)7


#endif /* MCAL_ADC_ADC_REGISTER_H_ */

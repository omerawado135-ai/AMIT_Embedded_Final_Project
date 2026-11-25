#ifndef MCAL_DIO_DIO_INIT_H_
#define MCAL_DIO_DIO_INIT_H_


#define DIO_PORTA    0
#define DIO_PORTB    1
#define DIO_PORTC    2
#define DIO_PORTD    3

#define DIO_PIN7 7

#define DIO_PIN_OUTPUT   1
#define DIO_PIN_INPUT    0

#define DIO_PIN_HIGH   1
#define DIO_PIN_LOW    0

#define DIO_PORT_OUTPUT  0xFF
#define DIO_PORT_INPUT  0x00

#define DIO_PORT_HIGH  0xFF
#define DIO_PORT_LOW   0X00  

typedef enum{
	PA0,PA1,PA2,PA3,PA4,PA5,PA6,PA7,
	PB0,PB1,PB2,PB3,PB4,PB5,PB6,PB7,
	PC0,PC1,PC2,PC3,PC4,PC5,PC6,PC7,
	PD0,PD1,PD2,PD3,PD4,PD5,PD6,PD7
}PIN_NUM;

void DIO_vidSetPortDir(u8 Copy_u8port,u8 u8CopyDir);
void DIO_vidSetPortVal(u8 Copy_u8port,u8 Copy_u8val);
u8 DIO_u8GetPortVal(u8 Copy_u8port);

void DIO_vidSetPinDir(u8 Copy_u8pin,u8 Copy_u8dir);
void DIO_vidSetPinVal(u8 Copy_u8pin,u8 Copy_u8val);
u8 DIO_u8GetPinVal(u8 Copy_u8pin);

void DIO_vidTogPinVal(u8 Copy_u8pin);
void DIO_vidTogPortVal(u8 Copy_u8port);

void DIO_vidSetPinsDir(u8 *u8Pin,u8 u8CopyBound,u8 Copy_u8dir);
void DIO_vidSetPinsVal(u8 *u8Pin,u8 u8CopyBound,u8 Copy_u8val);



#endif /* MCAL_DIO_DIO_INIT_H_ */

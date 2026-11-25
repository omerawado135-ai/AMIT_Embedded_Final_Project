
#include "../../utils/STD_TYPES.h"
#include "../../utils/bit_math.h"
#include "DIO_register.h"
#include "DIO_interface.h"



volatile u8 *Arr_DIR[4]  ={DDRA_REG,DDRB_REG,DDRC_REG,DDRD_REG};
volatile u8 *Arr_PORT[4] ={PORTA_REG,PORTB_REG,PORTC_REG,PORTD_REG,};
volatile u8 *Arr_Pin[4]  ={PINA_REG,PINB_REG,PINC_REG,PIND_REG,};

void DIO_vidSetPortDir(u8 Copy_u8port,u8 Copy_u8dir){
	if(Copy_u8port <= DIO_PORTD){
		*Arr_DIR[Copy_u8port] = Copy_u8dir;
	}
}
void DIO_vidSetPortVal(u8 Copy_u8port,u8 Copy_u8val){
	if(Copy_u8port <= DIO_PORTD){
		*Arr_PORT[Copy_u8port] = Copy_u8val;
	}

}
u8 DIO_u8GetPortVal(u8 Copy_u8port){
	u8 Copy_Data =0;
	if(Copy_u8port <= DIO_PORTD){
		Copy_Data = *Arr_Pin[Copy_u8port];
	}
	return Copy_Data;
}



void DIO_vidSetPinDir(u8 Copy_u8pin,u8 Copy_u8dir){
	switch(Copy_u8dir){
	case DIO_PIN_INPUT  :   CLR_BIT(*Arr_DIR[Copy_u8pin / 8] , (Copy_u8pin % 8)); break;
	case DIO_PIN_OUTPUT :   SET_BIT(*Arr_DIR[Copy_u8pin / 8] , (Copy_u8pin % 8)); break;
	}
}

void DIO_vidSetPinVal(u8 Copy_u8pin,u8 Copy_u8val){
	switch(Copy_u8val){
	case DIO_PIN_HIGH : SET_BIT(*Arr_PORT[Copy_u8pin / 8] , (Copy_u8pin % 8)); break;
	case DIO_PIN_LOW  : CLR_BIT(*Arr_PORT[Copy_u8pin / 8] , (Copy_u8pin % 8)); break;
	}
}
u8 DIO_u8GetPinVal(u8 Copy_u8pin){
	return GET_BIT(*Arr_PORT[Copy_u8pin / 8] , (Copy_u8pin % 8));
}


void DIO_vidSetPinsDir(u8 *u8Pin,u8 u8CopyBound,u8 Copy_u8dir){
	u8 Local_u8iterator;
	for(Local_u8iterator = 0;Local_u8iterator<u8CopyBound;Local_u8iterator++){
		switch(Copy_u8dir){
		case DIO_PIN_OUTPUT:SET_BIT(*Arr_DIR[(u8Pin[Local_u8iterator]/8)],(u8Pin[Local_u8iterator]%8));break;
		case DIO_PIN_INPUT :CLR_BIT(*Arr_DIR[(u8Pin[Local_u8iterator]/8)],(u8Pin[Local_u8iterator]%8));break;
		}
	}
}

void DIO_vidSetPinsVal(u8 *u8Pin,u8 u8CopyBound,u8 Copy_u8val){
	u8 Local_u8iterator;
	for(Local_u8iterator = 0; Local_u8iterator <u8CopyBound;Local_u8iterator++){
		switch(Copy_u8val){
		case DIO_PIN_HIGH :SET_BIT(*Arr_PORT[(u8Pin[Local_u8iterator]/8)],(u8Pin[Local_u8iterator]%8));break;
		case DIO_PIN_LOW  :CLR_BIT(*Arr_PORT[(u8Pin[Local_u8iterator]/8)],(u8Pin[Local_u8iterator]%8));break;
		}
	}
}

void DIO_vidTogPinVal(u8 Copy_u8pin)
{
	if (Copy_u8pin <= DIO_PIN7)
	{
		TOG_BIT(*Arr_PORT[Copy_u8pin / 8],Copy_u8pin % 8);
	}else{
		//error
	}
}
void DIO_vidTogPortVal(u8 Copy_u8port)
{
	if(Copy_u8port <= DIO_PORTD)
	{
		*Arr_PORT[Copy_u8port] = ~(*Arr_PORT[Copy_u8port]);
	}
}
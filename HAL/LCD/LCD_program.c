/*
 * lcd_Prog.c
 *
 *  Created on: ١٥‏/٠٨‏/٢٠٢٦
 *      Author: Omar
 */
#define F_CPU 1000000UL   

#include "../../utils/STD_TYPES.h"
#include "../../utils/bit_math.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_confg.h"
#include "LCD_interface.h"
#include <util/delay.h>



#if LCD_MODE == LCD_8BIT_MODE



void LCD_vid8BitInit(){
	DIO_vidSetPortDir(LCD_PORT,DIO_PORT_OUTPUT);
	DIO_vidSetPinDir(RS,DIO_PIN_OUTPUT);
	DIO_vidSetPinDir(E,DIO_PIN_OUTPUT);
	_delay_ms(40);
	LCD_vid8BitWriteCmd(LCD_CMD_8BIT_MODE);
	_delay_ms(1);
	LCD_vid8BitWriteCmd(LCD_CMD_DISPLAY_ON);
	_delay_ms(1);
	LCD_vid8BitWriteCmd(LCD_CMD_CLEAR_DIS);
	_delay_ms(2);
	LCD_vid8BitWriteCmd(LCD_CMD_ENTRY_MODE_INC);
}

void LCD_vid8BitWriteCmd(u8 u8CopyCMD){
	DIO_vidSetPinVal(RS,DIO_PIN_LOW);
	DIO_vidSetPortVal(LCD_PORT,u8CopyCMD);
	DIO_vidSetPinVal(E,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_vidSetPinVal(E,DIO_PIN_LOW);
	_delay_ms(1);
}

void LCD_vid8BitWriteChar(u8 u8CopyChar){
	DIO_vidSetPinVal(RS,DIO_PIN_HIGH);
	DIO_vidSetPortVal(LCD_PORT,u8CopyChar);
	DIO_vidSetPinVal(E,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_vidSetPinVal(E,DIO_PIN_LOW);
	_delay_ms(1);
}


void LCD_voidSendString(u8* Copy_u8str)
{
    while (*Copy_u8str != '\0')
    	LCD_vid8BitWriteChar(*Copy_u8str++);
}


void LCD_vid8BitWriteInt(s32 s32CopyNumber){
	s8 i=0;
	u8 arr[11] ={0};
	if(s32CopyNumber < 0){
		LCD_vid8BitWriteChar('-');
		s32CopyNumber *= -1;
	}else if(s32CopyNumber == 0){
		LCD_vid4BitWriteChar('0');
	}
	while(s32CopyNumber){
		arr[i] = (u8)(s32CopyNumber % 10);
		s32CopyNumber /= 10;
		i++;
	}
	for(i = i -1; i >=0 ;i--){
		LCD_vid8BitWriteChar(arr[i] + '0');
	}
}
void CLCD_voidGotoXY(u8 Copy_u8x, u8 Copy_u8y)
{
	u8 Local_u8Address = Copy_u8x + (Copy_u8y * 0x40);
    SET_BIT(Local_u8Address, 7);

    LCD_vid8BitWriteCmd(Local_u8Address);
}



#elif LCD_MODE == LCD_4BIT_MODE

void LCD_vid4BitInit(){
	u8 i=0;
	DIO_vidSetPinsDir(LCD_4Bit_Data_Pin,4,DIO_PIN_OUTPUT);
	DIO_vidSetPinDir(RS,DIO_PIN_OUTPUT);
	DIO_vidSetPinDir(E,DIO_PIN_OUTPUT);
	DIO_vidSetPinVal(RS, DIO_PIN_LOW);
	DIO_vidSetPinVal(E,  DIO_PIN_LOW);
	_delay_ms(50);
	DIO_vidSetPinVal(RS,DIO_PIN_LOW);
	for(i =0;i<4;i++){
		DIO_vidSetPinVal(LCD_4Bit_Data_Pin[i],GET_BIT(LCD_CMD_4BIT_MODE,(4+i)));
	}
	DIO_vidSetPinVal(E,DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_vidSetPinVal(E,DIO_PIN_LOW);
	
	LCD_vid4BitWriteCmd(0x33);
	_delay_ms(5);
	LCD_vid4BitWriteCmd(0x32);
	_delay_ms(5);
	LCD_vid4BitWriteCmd(LCD_CMD_4BIT_MODE);
	_delay_ms(2);
	LCD_vid4BitWriteCmd(LCD_CMD_DISPLAY_ON);
	_delay_ms(2);
	LCD_vid4BitWriteCmd(LCD_CMD_CLEAR_DIS);
	_delay_ms(2);
	LCD_vid4BitWriteCmd(LCD_CMD_ENTRY_MODE_INC);
	_delay_ms(2);

}

void LCD_vid4BitWriteCmd(u8 u8CopyCMD){
	u8 i=0;
	DIO_vidSetPinVal(RS,DIO_PIN_LOW);
	for(i =0;i<4;i++){
		DIO_vidSetPinVal(LCD_4Bit_Data_Pin[i],GET_BIT(u8CopyCMD,(4+i)));
	}
	_delay_us(50);
	DIO_vidSetPinVal(E,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_vidSetPinVal(E,DIO_PIN_LOW);
	_delay_us(50);

	for(i =0;i<4;i++){
		DIO_vidSetPinVal(LCD_4Bit_Data_Pin[i],GET_BIT(u8CopyCMD,(i)));
	}
	_delay_us(50);
	DIO_vidSetPinVal(E,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_vidSetPinVal(E,DIO_PIN_LOW);
	_delay_ms(2);
}

void LCD_vid4BitWriteChar(u8 u8CopyChar){
	u8 i=0;
	DIO_vidSetPinVal(RS,DIO_PIN_HIGH);
	for(i =0;i<4;i++){
		DIO_vidSetPinVal(LCD_4Bit_Data_Pin[i],GET_BIT(u8CopyChar,(4+i)));
	}
	_delay_us(50);
	DIO_vidSetPinVal(E,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_vidSetPinVal(E,DIO_PIN_LOW);
	_delay_us(50);

	for(i =0;i<4;i++){
		DIO_vidSetPinVal(LCD_4Bit_Data_Pin[i],GET_BIT(u8CopyChar,(i)));
	}
	_delay_us(50);
	DIO_vidSetPinVal(E,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_vidSetPinVal(E,DIO_PIN_LOW);
	_delay_ms(1);
}
void LCD_vid4bitSendString(u8* Copy_u8str)
{
    while (*Copy_u8str != '\0')
    	LCD_vid4BitWriteChar(*Copy_u8str++);
}


void LCD_vid4BitWriteFloat(f32 f32CopyNumber)
{
   s32 copy_num=(s32)f32CopyNumber;
   s32 f;
   s8 i=0;
   u8 arr[11]={0};

   if(copy_num < 0){
       LCD_vid4BitWriteChar('-');
       copy_num *= -1;
       f32CopyNumber = -f32CopyNumber;
   }else if(copy_num == 0){
       LCD_vid4BitWriteChar('0');
   }

   f=(s32)((f32CopyNumber - copy_num) * 1000);

   while(copy_num){
       arr[i] = (u8)(copy_num % 10);
       copy_num /= 10;
       i++;
   }
   for(i = i -1; i >=0 ;i--){
       LCD_vid4BitWriteChar(arr[i] + '0');
   }
   LCD_vid4BitWriteChar('.');
   LCD_vid4BitWriteChar((f/100) + '0');
   LCD_vid4BitWriteChar(((f/10) % 10) + '0');
   LCD_vid4BitWriteChar((f%10)  + '0');
   DIO_vidSetPinVal(E,DIO_PIN_HIGH);
   _delay_ms(1);
   DIO_vidSetPinVal(E,DIO_PIN_LOW);
   _delay_ms(1);
}
void LCD_vid4BitWriteInt(s32 s32CopyNumber){
	s8 i=0;
	u8 arr[11] ={0};
	if(s32CopyNumber < 0){
		LCD_vid4BitWriteChar('-');
		s32CopyNumber *= -1;
	}else if(s32CopyNumber == 0){
		LCD_vid4BitWriteChar('0');
	}
	while(s32CopyNumber){
		arr[i] = (u8)(s32CopyNumber % 10);
		s32CopyNumber /= 10;
		i++;
	}
	for(i = i -1; i >=0 ;i--){
		LCD_vid4BitWriteChar(arr[i] + '0');
	}

}


void CLCD_voidGotoXY(u8 Copy_u8x, u8 Copy_u8y)
{
	u8 Local_u8Address = Copy_u8x + (Copy_u8y * 0x40);
    SET_BIT(Local_u8Address, 7);

    LCD_vid4BitWriteCmd(Local_u8Address);
}

#endif

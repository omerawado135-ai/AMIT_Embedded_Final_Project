/*
 * lcd_conf.h
 *
 *  Created on: ١٥‏/٠٨‏/٢٠٢٦
 *      Author: Omar
 */

#ifndef HAL_LCD_LCD_CONF_H_
#define HAL_LCD_LCD_CONF_H_


/********** Mode of LCD ****************/
#define LCD_8BIT_MODE       0
#define LCD_4BIT_MODE       1
#define LCD_MODE      LCD_4BIT_MODE


/******* LCD Data 8Pin ******/
#define LCD_PORT    PORTB

/******* LCD Data 4Pin ******/
extern u8 LCD_4Bit_Data_Pin[4];

/******** LCD Control Pin *********/
#define RS  PD1
#define E   PD2


#endif /* HAL_LCD_LCD_CONF_H_ */

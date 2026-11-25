/*
 * lcd_Init.h
 *
 *  Created on: ١٥‏/٠٨‏/٢٠٢٦
 *      Author: Omar
 */

#ifndef HAL_LCD_LCD_INIT_H_
#define HAL_LCD_LCD_INIT_H_



#define LCD_CMD_CLEAR_DIS         0x01
#define LCD_CMD_RETURN_HOME       0x02
#define LCD_CMD_8BIT_MODE         0x38
#define LCD_CMD_4BIT_MODE         0x28
#define LCD_CMD_ADD_DDRAM         0x80
#define LCD_CMD_ADD_CGRAM         0x40
#define LCD_CMD_SHIFT_DIS_RIGHT   0x1C
#define LCD_CMD_SHIFT_DIS_LEFT    0x18
#define LCD_CMD_ENTRY_MODE_INC    0x06
#define LCD_CMD_ENTRY_MODE_DEC    0x04
#define LCD_CMD_DISPLAY_ON        0x0C
#define LCD_CMD_DISPLAY_OFF       0x08
#define LCD_CMD_CURSOR_ONBLINK    0x0F
#define LCD_CMD_CURSOR_OFFBLINK   0x0E


#define LCD_SEG_ROW1     0
#define LCD_SEG_ROW2     1

/******** 8Bit Function's ********/

void LCD_vid8BitInit();
void LCD_vid8BitWriteCmd(u8 u8CopyCMD);
void LCD_vid8BitWriteChar(u8 u8CopyChar);
void LCD_voidSendString(u8* Copy_u8str);
void LCD_vid8BitWriteInt(s32 s32CopyNumber);
void LCD_vid8BitWriteFloat(f32 f32CopyNumber);
void CLCD_voidGotoXY(u8 Copy_u8x, u8 Copy_u8y);

/******** 4Bit Function's ********/

void LCD_vid4BitInit();
void LCD_vid4BitWriteCmd(u8 u8CopyCMD);
void LCD_vid4BitWriteChar(u8 u8CopyChar);
void LCD_vid4bitSendString(u8* Copy_u8str);
void LCD_vid4BitWriteInt(s32 s32CopyNumber);
void CLCD_voidGotoXY(u8 Copy_u8x, u8 Copy_u8y);

#endif /* HAL_LCD_LCD_INIT_H_ */

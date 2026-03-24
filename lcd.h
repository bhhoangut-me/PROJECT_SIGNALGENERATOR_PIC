#ifndef LCD_H
#define LCD_H
#include "bsp.h"
#include <xc.h>

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 4000000
#endif

void LCD_Init();
void LCD_Command(unsigned char cmd);
void LCD_Char(char data);
void LCD_String(const char *str);
void LCD_Clear();
void LCD_SetCursor(unsigned char row, unsigned char col);

#endif
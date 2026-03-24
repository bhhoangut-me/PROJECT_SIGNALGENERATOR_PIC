#include "lcd.h"

void LCD_Enable() {
    EN = 1;
    __delay_us(40); 
    EN = 0;
    __delay_us(40);
}


void LCD_Command(unsigned char cmd) {
    RS = 0;             
    LCD_DATA = cmd;     
    LCD_Enable();
    if (cmd <= 0x02) __delay_ms(2); 
}

void LCD_Char(char data) {
    RS = 1;             
    LCD_DATA = data;    
    LCD_Enable();
}


void LCD_String(const char *str) {
    while (*str) {
        LCD_Char(*str++);
    }
}

void LCD_Clear() {
    LCD_Command(0x01);
}


void LCD_SetCursor(unsigned char row, unsigned char col) {
    unsigned char addr;
    if (row == 1) addr = 0x80 + (col - 1);
    else addr = 0xC0 + (col - 1);
    LCD_Command(addr);
}


void LCD_Init() {
    __delay_ms(20);      
    LCD_Command(0x38);   
    LCD_Command(0x0C);   
    LCD_Command(0x06);   
    LCD_Clear();         
}
#include "bsp.h"
#include "lcd.h"
#include <stdio.h>
#include <stdint.h>
#include "init.h"
#include "SPI.h"
#pragma config WDTE = OFF
volatile uint8_t var_mode = 0;
int main(void) {
    init(); 
    while(1) {
       LCD_SetCursor(1,1);
       if(!var_mode){
           LCD_String("MODE : SIN   ");
       }
       else{
           LCD_String("MODE : PULSE ");
       }
       __delay_ms(20);
    }
}

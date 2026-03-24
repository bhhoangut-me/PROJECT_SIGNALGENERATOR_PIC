#include "init.h"
#include "bsp.h"
#include "lcd.h"
void init(){
    //Set up Digital Pin
    ANSEL = 0;
    ANSELH = 0;
    //Set up LCD Pin
    TRISD = 0x00;
    TRISAbits.TRISA0 = 0;
    TRISAbits.TRISA1 = 0;
    //Set up SPI Pin
    TRISCbits.TRISC3 = 0; 
    TRISCbits.TRISC5 = 0; 
    TRISCbits.TRISC4 = 1; 
    TRISCbits.TRISC2 = 0;
    FSYNC = 1;
    SSPCON = 0b00110010; // bit 5 : Enable SPI ,bit 4 : Default HIGH, bit 3-0 : Fosc/64
    SSPSTATbits.CKE = 1 ; // bit CKE : Push Data Rising Pulse
    SSPSTATbits.SMP = 0;
    // Set up EXTERNAL INTERRUPT 
    TRISBbits.TRISB0 = 1;
    OPTION_REGbits.INTEDG = 1;
    INTCONbits.INTF = 0;        
    INTCONbits.INTE = 1;        
    INTCONbits.GIE = 1;         
    INTCONbits.PEIE = 1;
    LCD_Init();
}
#include "mode.h"
#include "SPI.h"
void generate_sinwave(void){
    Write_AD9833(0x2100); 
    Write_AD9833(0x4000 | 0x29F1); 
    Write_AD9833(0x4000 | 0x0000); 
    Write_AD9833(0x2000); 
}
void generate_pulse(void){
    Write_AD9833(0x2100); 
    Write_AD9833(0x4000 | 0x29F1); 
    Write_AD9833(0x4000 | 0x0000); 
    Write_AD9833(0x202A); 
}
#include "bsp.h"
#include "SPI.h"
void Write_AD9833(uint16_t cmd){
    uint8_t dummy;
    FSYNC = 0; // Start 
    SSPBUF = (uint8_t)(cmd >> 8 );
    while(!SSPSTATbits.BF); // Wait send 8 bit 
    dummy = SSPBUF ; 
    SSPBUF = (uint8_t)(cmd & 0xFF);
    while(!SSPSTATbits.BF);
    dummy = SSPBUF ; 
    FSYNC = 1;
}

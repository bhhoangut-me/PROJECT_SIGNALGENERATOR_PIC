#ifndef LCD_H
#define LCD_H
#include <stdint.h>
extern volatile uint8_t var_mode;
void __interrupt() func_mode(void);
#endif
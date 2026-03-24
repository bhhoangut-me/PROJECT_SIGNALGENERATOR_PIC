#include "interrupt.h"
#include "mode.h"
void __interrupt() func_mode(void){
    if(INTF){
        var_mode=(var_mode+1)%2;
        if(!var_mode){ // MODE : SIN
            generate_sinwave();
        }
        else{ // MODE : PULSE
            generate_pulse();
        }
        INTF=0;
    }
}

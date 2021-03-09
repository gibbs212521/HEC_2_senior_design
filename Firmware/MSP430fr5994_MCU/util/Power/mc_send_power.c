#include <stdio.h>
#include "mc_power.h"

void mc_power_on(void){
    /// Turns on power in transmitter for oscillator
    /*  VARIABLE DESCRIPTIONS
    TRANS_EN_PIN :: P5.7
        Set to 3.33 V to drive Oscillator of Transmitter Driver
    */
   P5OUT |= BIT7;

    /*  TODO LIST:
        TRANS_EN_PIN to 3.33 V stable
        Bluetooth function (Transmit_On) needed
    */

    return;
}

void mc_power_off(void){
    /// Turns off power in transmitter for oscillator
    P5OUT &= ~BIT7;
    /*  TODO LIST:
        TRANS_EN_PIN to 3.33 V stable
        Bluetooth function (Transmit_Off) needed
    */
    return;
}

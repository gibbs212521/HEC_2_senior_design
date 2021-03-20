#include "mcu_reset.h"
#include <stdio.h>

short mc_reset(){
    WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5; // power mode 5 control register 0 locks LPM5 bit
    P1DIR |= 0x03;

    printf("Resetting Micro Controller Unit Now....");
//    main_clock_interrupt(); /// TO-DO: Create a means of adjusting main clock interrupt function.
//      Remove GLOBAL interrupt function and instantiate a new one for main interrupt clock.
    return 0;
}

#include "mcu_setup.h"
#include <stdio.h>

short mc_setup(){
    WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5; // power mode 5 control register 0 locks LPM5 bit
                                           // to activate previously configured port settings
    P1DIR |= 0x03;                          // Set P1 to null output direction sic b'00000000
//    P1DIR |= 0x01;                          // Set P1.0 to output direction sic b'00000001' (n.b. bit#=0)
//    P1DIR |= 0x02;                          // Set P1.1 to output direction sic b'00000010' (n.b. bit#=1)
//    P1DIR |= 0x03;                          // Set P1.1 to output direction sic b'00000010' (n.b. bit#=0 & 1)

    printf("Setting Up Micro Controller Unit Now....");
//    main_clock_interrupt();
    set_button_interrupts();
    if(P1IV__P1IFG7){
        P1OUT ^= 0x01;                           // Setting MCU to only have red or green light lit when toggling.
    }

//    P5DIR = 0b01000000;

    return 0;
}


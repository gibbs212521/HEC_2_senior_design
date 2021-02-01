#include "mcu_setup.h"
#include <stdio.h>

short mc_setup(){
   WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
   PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                           // to activate previously configured port settings
   P1DIR |= 0x03;                          // Set P1 to null output direction sic b'00000000
//    P1DIR |= 0x01;                          // Set P1.0 to output direction sic b'00000001' (n.b. bit#=0)
//    P1DIR |= 0x02;                          // Set P1.1 to output direction sic b'00000010' (n.b. bit#=1)
//    P1DIR |= 0x03;                          // Set P1.1 to output direction sic b'00000010' (n.b. bit#=0 & 1)

    printf("Setting up Micro Controller Unit Now....");
    main_clock_interrupt();
    return 0;
}

#include "mcu_setup.h"
#include <stdio.h>


void SetDir(extern volatile unsigned char (*pCMD), int pins){
    *pCMD |= pins;
}

short mc_setup(){
    WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5; // power mode 5 control register 0 locks LPM5 bit
                                           // to activate previously configured port settings
//    P1DIR |= 0x03;                          // Set P1 to null output direction sic b'00000000

//    P1DIR |= 0x01;                          // Set P1.0 to output direction sic b'00000001' (n.b. bit#=0)
//    P1DIR |= 0x02;                          // Set P1.1 to output direction sic b'00000010' (n.b. bit#=1)
//    P1DIR |= 0x03;                          // Set P1.1 to output direction sic b'00000010' (n.b. bit#=0 & 1)

//    GetVoltage();
    SetDir(&P1DIR, 0x01);
    printf("Setting Up Micro Controller Unit Now....");
//    main_clock_interrupt();
//    set_button_interrupts();  /// <-- Requires a test-board suite before reimplementing & a method to check for test board

/// TO-DO: We need to integrate interrupts by grade / priority levels.

    return 0;
}


//***************************************************************************************
//  MSP430 Blink the LED Demo - Software Toggle P1.0
//
//  Description; Toggle P1.0 by xor'ing P1.0 inside of a software loop.
//  ACLK = n/a, MCLK = SMCLK = default DCO
//
//                MSP430x5xx
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//            |             P1.0|-->LED
//
//  Texas Instruments, Inc
//  July 2013
//***************************************************************************************

#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    P1DIR |= 0x02;                          // Set P1.1 to output direction sic b'00000010' (n.b. bit#=1)
//    P1DIR |= 0x01;                          // Set P1.0 to output direction sic b'00000001' (n.b. bit#=0)

    for(;;) {
        volatile unsigned int i;            // volatile to prevent optimization

        P1OUT ^= 0x03;                      // Toggle P1.0 using exclusive-OR

        i = 0xffff;                         // SW Delay via do-while loop
        do i--;
        while(i != 0);
                                            // infinite for loop repeats to toggle off/on P1
    }
}

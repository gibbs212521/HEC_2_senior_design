//#include <stdio.h>
//#include <stdlib.h>
//#include <comm_protocol.h>
#include <msp430fr5994.h>
//#include <msp430fr5994_mockup.h>
/// msp430fr5994_mockup.h should be used for testing without MSP430fr5994 MCU.

/// Due to msp430.h, renamed msp430.c to msp430_proj.c to avoid any relation between the this file and msp430.h.

void main() {
//   printf("Hello World!");
   WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
   PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                           // to activate previously configured port settings
   P1DIR |= 0x03;                          // Set P1 to null output direction sic b'00000000
//    P1DIR |= 0x01;                          // Set P1.0 to output direction sic b'00000001' (n.b. bit#=0)
//    P1DIR |= 0x02;                          // Set P1.1 to output direction sic b'00000010' (n.b. bit#=1)
//    P1DIR |= 0x03;                          // Set P1.1 to output direction sic b'00000010' (n.b. bit#=0 & 1)

   for(;;) {
       volatile unsigned int i;            // volatile to prevent optimization

       P1OUT ^= 0x03;                      // Toggle P1.0 using exclusive-OR

       i =0x1000;                         // SW Delay via do-while loop
       do i--;
       while(i != 0);
                                           // infinite for loop repeats to toggle off/on P1
   }
}

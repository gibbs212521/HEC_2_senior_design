#include "button_interrupt.h"

void set_button_interrupts(){
    P5DIR = 0xFF;
    P5OUT = 0x00;

    // Configure GPIO
    P5OUT = BIT6;                           // Pull-up resistor on P1.1
    P5REN = BIT6;                           // Select pull-up mode for P1.1
    P5DIR = 0xFF ^ BIT6;                    // Set all but P1.1 to output direction
//    P5IES = BIT6;                           // P1.1 Hi/Lo edge
    P5IFG = 0;                              // Clear all P1 interrupt flags
    P5IE = BIT6;                            // P1.1 interrupt enabled


    // Disable the GPIO power-on default high-impedance mode to activate
    // previously configured port settings
    PM5CTL0 &= ~LOCKLPM5;

    while(1)
    {
        __bis_SR_register(LPM4_bits | GIE); // Enter LPM4 w/interrupt
        __no_operation();                   // For debugger
//        P1OUT ^= BIT0;                      // P1.0 = toggle Breaks interrupt
    }
}


//#pragma vector = P5IV__P5IFG7 // Set Compiler watch Port 5 Interrupt Vector for pin 6
#pragma vector = PORT5_VECTOR // Set Compiler watch Port 5 Interrupt Vector for pin 6
__interrupt void PORT5_PIN6_BUTTON_ISR(void)
{
    switch(__even_in_range(P5IV, P5IV__P5IFG7))
    {
        case P5IV__NONE:    break;          // Vector  0:   No interrupt
        case P5IV__P5IFG0:  break;          // Vector  2:   P5.0 interrupt flag
        case P5IV__P5IFG1:  break;          // Vector  4:   P5.1 interrupt flag
        case P5IV__P5IFG2:  break;          // Vector  6:   P5.2 interrupt flag
        case P5IV__P5IFG3:  break;          // Vector  8:   P5.3 interrupt flag
        case P5IV__P5IFG4:  break;          // Vector  10:  P5.4 interrupt flag
        case P5IV__P5IFG5:  break;          // Vector  12:  P5.5 interrupt flag
        case P5IV__P5IFG6:  
            // P5IES ^= BIT1;                  // Toggle interrupt edge
            __bic_SR_register_on_exit(LPM4_bits); // Exit LPM4
            // P1OUT ^= 0x03;                      // Toggles Green LED (Port 1 Pin 1)
            break;                          // Vector  14:  P5.6 interrupt flag
        case P5IV__P5IFG7:  break;          // Vector  16:  P5.7 interrupt flag
        default: break;
    }
}

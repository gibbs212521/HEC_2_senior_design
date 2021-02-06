#include "button_interrupt.h"

/// TODO: Move toward Port 2 with pins 2,3,4,& 7 for interrupt 
///         via replacing BIT6 with BIT_REFERENCE
///     AND
///         via replacing P5 with P2
///     DON'T FORGET: to handle interrupt cases at bottom of c file with FUNCTIONS
///         Assign Functions above interrupt cases
///         Define Functions in Header File

void set_button_interrupts(){
    P2DIR = 0xFF;
    P2OUT = 0x00;

    // Configure GPIO
    P2OUT = BUTTON_INTERRUPT_BIT_REFERENCE; // 0x9C;                           // Pull-up resistor on P1.1
    P2REN = BUTTON_INTERRUPT_BIT_REFERENCE; // 0b10011100;                           // Select pull-up mode for P1.1
    P2DIR = 0xFF ^ BUTTON_INTERRUPT_BIT_REFERENCE;                    // Set all but P1.1 to output direction
//    P2IES = BUTTON_INTERRUPT_BIT_REFERENCE;                           // P1 Hi/Lo edge
    P2IFG = 0;                              // Clear all P1 interrupt flags
    P2IE = BUTTON_INTERRUPT_BIT_REFERENCE;                            // P1.1 interrupt enabled


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

void button0_push(){ // Port 2 Pin 2
    P1OUT ^= 0X03; // toggles both red and green LEDs
}

void button1_push(){ // Port 2 Pin 3
    P1OUT ^= 0X03; // toggles both red and green LEDs
}
void button2_push(){ // Port 2 Pin 4
    P1OUT ^= 0X03; // toggles both red and green LEDs
}
void button3_push(){ // Port 2 Pin 7
    P1OUT ^= 0X03; // toggles both red and green LEDs
}

//#pragma vector = P2IV__P2IFG7 // Set Compiler watch Port 2 Interrupt Vector
#pragma vector = PORT2_VECTOR // Set Compiler watch Port 2 Interrupt Vector
__interrupt void PORT2_BUTTON_ISR(void)
{
    switch(__even_in_range(P2IV, P2IV__P2IFG7))
    {
        case P2IV__NONE:    break;          // Vector  0:   No interrupt
        case P2IV__P2IFG0:  break;          // Vector  2:   P2.0 interrupt flag
        case P2IV__P2IFG1:  break;          // Vector  4:   P2.1 interrupt flag
        case P2IV__P2IFG2:
            button0_push();
            break;          // Vector  6:   P2.2 interrupt flag
        case P2IV__P2IFG3:
            button1_push();
            break;          // Vector  8:   P2.3 interrupt flag
        case P2IV__P2IFG4:
            button2_push();
            break;          // Vector  10:  P2.4 interrupt flag
        case P2IV__P2IFG5:  break;          // Vector  12:  P2.5 interrupt flag
        case P2IV__P2IFG6:  break;          // Vector  14:  P2.6 interrupt flag
        case P2IV__P2IFG7:
            button3_push();
            break;          // Vector  16:  P2.7 interrupt flag
        default: break;
     }
}

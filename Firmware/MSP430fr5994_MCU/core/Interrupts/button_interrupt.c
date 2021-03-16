#include "button_interrupt.h"

/// TODO: Move toward Port 2 with pins 2,3,4,& 7 for interrupt 
///         via replacing BIT6 with BIT_REFERENCE
///     AND
///         via replacing P5 with P2
///     DON'T FORGET: to handle interrupt cases at bottom of c file with FUNCTIONS
///         Assign Functions above interrupt cases
///         Define Functions in Header File

short _compile_transmitter = 0x00;

void set_button_interrupts(short build_transmitter){
    if (build_transmitter==0x01){
        P1OUT |= 0x03;
        _compile_transmitter = 0x01;
    }
    // P5DIR = 0xFF;
    // P5OUT = 0x00;
    P5OUT = 0b01100000;
    P5REN = 0b01100000;
    P5DIR = 0xff ^ 0b01100000;
    P5IFG = 0;
    P5IE = 0b01100000;

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

//     while(1)
//     {
//         __bis_SR_register(LPM4_bits | GIE); // Enter LPM4 w/interrupt
//         __no_operation();                   // For debugger
// //        P1OUT ^= BIT0;                      // P1.0 = toggle Breaks interrupt
//     }
}


void button0_push(){ // Port 2 Pin 2
    if (_compile_transmitter == 0x01){
    P5OUT ^= 0X01;  /// Enables Transmitter's Coil
    P1OUT ^= 0x03;
    } else {
    P5OUT ^= 0x08;
    P1OUT ^= 0x01;
    };
}


void button1_push(){ // Port 2 Pin 3
   P5OUT ^= 0X06; // toggles both red and green LEDs
   P1OUT &= ~0x03;
}
void button2_push(){ // Port 2 Pin 4
   P5OUT ^= 0X06; // toggles both red and green LEDs
}
void button3_push(){ // Port 2 Pin 7
   P5OUT ^= 0X06; // toggles both red and green LEDs
}

//#pragma vector = P2IV__P2IFG7 // Set Compiler watch Port 2 Interrupt Vector
#pragma vector = PORT2_VECTOR // Set Compiler watch Port 2 Interrupt Vector
__interrupt void PORT2_BUTTON_ISR(void){
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

//#pragma vector = P5IV__P5IFG7 // Set Compiler watch Port 5 Interrupt Vector for pin 6
#pragma vector = PORT5_VECTOR // Set Compiler watch Port 5 Interrupt Vector for pin 6
__interrupt void PORT5_PIN6_BUTTON_ISR(void)
{
    switch(__even_in_range(P5IV, P5IV__P5IFG7))
    {
        case P5IV__NONE:
        // __bic_SR_register_on_exit(LPM4_bits); // Exit LPM4
        break;          // Vector  0:   No interrupt
        case P5IV__P5IFG0:  break;          // Vector  2:   P5.0 interrupt flag
        case P5IV__P5IFG1:  break;          // Vector  4:   P5.1 interrupt flag
        case P5IV__P5IFG2:  break;          // Vector  6:   P5.2 interrupt flag
        case P5IV__P5IFG3:  break;          // Vector  8:   P5.3 interrupt flag
        case P5IV__P5IFG4:  break;          // Vector  10:  P5.4 interrupt flag
        case P5IV__P5IFG5:  button1_push();
        break;          // Vector  12:  P5.5 interrupt flag
        case P5IV__P5IFG6:                    // Toggles Green LED (Port 1 Pin 1)
            button0_push();
            break;                          // Vector  14:  P5.6 interrupt flag
        case P5IV__P5IFG7:  break;          // Vector  16:  P5.7 interrupt flag
        default:  break;
    };
}

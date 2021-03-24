#include "mc_test_lcd.h"

void testLCD(){
    


    // WDTCTL= WDTPW + WDTSSEL_0 + WDTTMSEL + WDTIS_2; // Setup Watch dog timer for 0.5 second tick using 16MHz DCO on MSP430FR5994
    // SFRIE1 |= WDTIE;// Set range to calibrated 1MHz
    // Unlock the system.
    P3DIR |= 0xFF;      // Enables all pins on Port 4 as LCD Output Port
    P8DIR |= 0x01;      // Enables LCD ENABLE PIN
    P7DIR |= 0x1C;      // Enables LCD RS, RW, & B

    P3OUT &= ~0xFF;     // Below sets all pins to LOW
    P8OUT &= ~0x01;
    P7OUT &= ~0x1C;

    // P4DIR |= 0xFF;      // Enables all pins on Port 4 as LCD Output Port
    // P8DIR |= 0x01;      // Enables LCD ENABLE PIN
    // P7DIR |= 0x1C;      // Enables LCD RS, RW, & B

    // P4OUT &= ~0xFF;     // Below sets all pins to LOW
    // P8OUT &= ~0x01;
    // P7OUT &= ~0x1C;
    



    // P1DIR = 0xFF;                                    // Set P1.0 (D0) to P1.7 (D7)
    // P2DIR = (0x01 | 0x02);                      // Set P2.0 (E) and P2.1 (RS) to output
    TA0CCR1  = 1000;                                 // Set CCR1 value for 31000 ms interrupt
    TA0CCTL1 = CCIE;                                  // Compare interrupt enable
    TA0CTL   = (TASSEL_2 | MC_2 | TACLR);  //SMCLK, Continuous mode
    __bis_SR_register( GIE );                            // Enable global interrupts
    hd44780_clear_screen();                             // Clear display content
    // while( 1 ){              
        hd44780_write_string( "HEC project!  ", 1, 1, NO_CR_LF );
    // }
}
// Directive for timer interrupt
#pragma vector = TIMER0_A1_VECTOR
__interrupt void timer_0_a1_isr( void ){                     // Timer 0 A1 interrupt service
  switch( TA0IV )                                                        // Determine interrupt source
  {
    case 2:                                                                   // CCR1 caused the interrupt
    {
        TA0CCR1 += 1000;
        hd44780_timer_isr();                                          // Call HD44780 state machine
        break;                                                                        // CCR1 interrupt handling done
    }
    default :
        break;
  }
}

int _system_pre_init( void ) // This function is called before anything else is done
{
  WDTCTL = (WDTPW | WDTHOLD); // Stop watchdog timer
  return 1; // Return 1
}

#include "mc_test_lcd.h"

void setUpLCD(){
    // WDTCTL= WDTPW + WDTSSEL_0 + WDTTMSEL + WDTIS_2; // Setup Watch dog timer for 0.5 second tick using 16MHz DCO on MSP430FR5994
    // SFRIE1 |= WDTIE;// Set range to calibrated 1MHz
    // Unlock the system.
    P2DIR |= 0x60;  // Allows attention to Port 2 Pins 5 & 6
    P4DIR |= 0x0E;  // Allows attention to Port 4 Pins 1, 2, & 3
    // NOTE Skip 1 pin
    P3DIR |= 0x78;  // Allows attention to Port 3 Pisn 4, 5, & 6  

    // P1DIR = 0xFF;                                    // Set P1.0 (D0) to P1.7 (D7)
    // P2DIR = (0x01 | 0x02);                      // Set P2.0 (E) and P2.1 (RS) to output
    TA1CCR1  = 31000;                                 // Set CCR1 value for 31000 ms interrupt
    TA1CCTL1 = CCIE;                                  // Compare interrupt enable
    TA1CTL   = (TASSEL_2 | MC_2 | TACLR);  //SMCLK, Continuous mode
    __bis_SR_register( GIE );                            // Enable global interrupts
    hd44780_clear_screen();                             // Clear display content
    uint8_t iterator=0;
    while( 1 )                                                       // Endless loop - main program
    {
        hd44780_write_string( "HEC project!", 1, 1, NO_CR_LF );
        hd44780_output_unsigned_16bit_value( iterator++, 2, 2, 1, 0 );
        if(iterator>10)
            iterator=0;
    }
}
// Directive for timer interrupt
#pragma vector = TIMER1_A1_VECTOR
__interrupt void timer_1_a1_isr( void )                     // Timer 0 A1 interrupt service
{
  switch( TA1IV )                                                        // Determine interrupt source
  {
    case 2:                                                                   // CCR1 caused the interrupt
    {
      hd44780_timer_isr();                                          // Call HD44780 state machine
      break;                                                                        // CCR1 interrupt handling done
    }
  }
}
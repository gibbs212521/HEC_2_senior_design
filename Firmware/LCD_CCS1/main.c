#include "lcd.h"                    //  lcd library
#include "msp430fr5994.h"           // Microcontroller specific
uint8_t value=0;
void main( void )
{
WDTCTL= WDTPW + WDTSSEL_0 + WDTTMSEL + WDTIS_2; // Setup Watch dog timer for 0.5 second tick using 16MHz DCO on MSP430FR5994
SFRIE1 |= WDTIE;// Set range to calibrated 1MHz
// Unlock the system.
  PM5CTL0 &= ~LOCKLPM5;
P1DIR = 0xFF;                                    // Set P1.0 (D0) to P1.7 (D7)
P2DIR = (0x01 | 0x02);                      // Set P2.0 (E) and P2.1 (RS) to output
  TA0CCR1  = 31000;                                 // Set CCR1 value for 31000 ms interrupt
  TA0CCTL1 = CCIE;                                  // Compare interrupt enable
  TA0CTL   = (TASSEL_2 | MC_2 | TACLR);  //SMCLK, Continuous mode
  __bis_SR_register( GIE );                            // Enable global interrupts
  hd44780_clear_screen();                             // Clear display content
  while( 1 )                                                       // Endless loop - main program
  {
    hd44780_write_string( "HEC project!", 1, 1, NO_CR_LF );
    hd44780_output_unsigned_16bit_value( value++, 2, 2, 1, 0 );
    if(value>10)
    value=0;
  }
}
// Directive for timer interrupt
#pragma vector = TIMER0_A1_VECTOR
__interrupt void timer_0_a1_isr( void )                     // Timer 0 A1 interrupt service
{
  switch( TA0IV )                                                        // Determine interrupt source
  {
    case 2:                                                                   // CCR1 caused the interrupt
    {
      hd44780_timer_isr();                                          // Call HD44780 state machine
      break;                                                                        // CCR1 interrupt handling done
    }
  }
}

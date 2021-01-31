/*
 * clock_interrupt.c
 *
 *  Created on: Jan 23, 2021
 *      Author: natashafranca
 */

#include "clock_interrupt.h"

void main_clock_interrupt(){
  WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer

  PM5CTL0 &= ~LOCKLPM5; // power mode 5 control register 0 locks LPM5 bit

  P1DIR |= 0x03;
  //P1DIR |= BIT0 ; // P1.0 is output pin sic 0b00000001 --> Red LED light
  P1OUT ^= 0x01; // Toggle P1

// setting CCIE bit in the TA0CCTL0 register
  TA0CCTL0 = CCIE; // TAxCCR0 interrupt enabled
// TA0CTL specifies Timer A0 control register
// TASSEL_2 selects SMCLK (1 MHz)                 /// TODO: Test 1MHz is true 1 micro second period
// SMCLK --> SM === Subsystem Master  :: Subsystem Master Clock
// With MC__UP, timer counts up to TAxCCR0
// ID__4 selects an internal 4x divider for the supplied clock 
// 1000 kHz / 4 = 250 kHz --> 250 ms period
  TA0CTL = TASSEL_2 | MC__UP | ID__4;
  TA0CCR0 = 62500; // Timer Limit :: Timer counts up to 10000 ticks  --> 0.25 second period :: Divide 65,000 by 1,000,000 & Multiply by 4
//  TA0CCR0 = 4; // Timer Limit :: Timer counts up to 4 ticks |-> 1 second period

  _enable_interrupt();

  while(1) // keeps looping for when main.c lacks an infinite loop

  {}
}

// Timer interrupt service routine
//#pragma vector = TIMER0_A1_VECTOR
#pragma vector = TIMER0_A0_VECTOR   // Set Compiler to note to Vector (Memory Address for TimerA0)
__interrupt void TIMERA_TIMER_OVERFLOW_ISR(void)  // Question on overflow datatype  /// Set interrupt error handler to respond when vector above is initiated with interrupt routine.
{
  P1OUT ^= BIT0; // Toggle P1.0
  /*
  Toggle Visualization
  P1OUT = 0b00011100
  P1OUT ^= BIT0; // Toggle P1.0
    P1OUT = P1OUT ^ BIT0
  P1OUT = 0b00000000 ^ 0b00000001
  P1OUT = true /// because BIT0 is high only in one of the two in the exclusive or comparison
  since P1DIR == BIT0, red light is high 
    Since P1OUT is high, all bits in P1DIR are high... and P1DIR only has bit 0 high (i.e. the red light)
  ---NEXT LOOP---    
  P1OUT ^= BIT0; // Toggle P1.0
  P1OUT = 0b00000001 ^ 0b00000001
  P1OUT = false /// because BIT0 is high in both P1DIR and BIT0 in exclusive OR comparison (i.e. red light will turn off now)
  */
}


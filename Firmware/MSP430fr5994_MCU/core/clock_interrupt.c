/*
 * clock_interrupt.c
 *
 *  Created on: Jan 23, 2021
 *      Author: natashafranca
 */

#include <msp430fr5994.h>

int main(void)
{
  WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer

  PM5CTL0 &= ~LOCKLPM5; // power mode 5 control register 0 locks LPM5 bit

  P1DIR |= BIT0; // P1.0 is output pin

// setting CCIE bit in the TA0CCTL0 register
  TA0CCTL0 = CCIE; // TAxCCR0 interrupt enabled
// TA0CTL specifies Timer Ax control register
// TASSEL_2 selects SMCLK (1 MHz)
// With MC_UP, timer counts up to TAxCCR0
// ID_4 selects an internal 4x divider for the supplied clock
  TA0CTL = TASSEL_2 | MC__UP | ID__4;
  TAxCCR0 = 10000;

  _enable_interrupt();

  while(1) // keeps looping
  {}
}

// Timer A1 interrupt service routine
#pragma vector = TIMER_A1_VECTOR
__interrupt void TIMERA_TIMER_OVERFLOW_ISR(void)
{
  P1OUT ^= BIT0; // Toggle P1.0
}


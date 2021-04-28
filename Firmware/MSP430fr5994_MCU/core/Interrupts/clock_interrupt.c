#include "clock_interrupt.h"

void main_clock_interrupt(){
    // setting CCIE bit in the TA0CCTL0 register
    TA0CCTL0 = CCIE; // TAxCCR0 interrupt enabled
    // TA0CTL specifies Timer A0 control register
    // TASSEL_2 selects SMCLK 
    // SMCLK --> SM === Subsystem Master  :: Subsystem Master Clock
    // With MC__UP, timer counts up to TAxCCR0
    // ID__4 selects an internal 4x divider for the supplied clock 
    // ID_0 selects an internal 1x divider for the supplied clock 
    // 1000 kHz / 4 = 250 kHz --> 250 ms period
    // TAIE === Timer A Interrupt Enabled Bit
    TA0CTL = TASSEL_2 | MC__UP | ID__8;// | TAIE;
    TA0CCR0 = 62500; // Timer 0 Limit :: Timer counts up to 62500 ticks
    //  Divide 62,500 by 8,000,000 & Multiply by 8  --> 0.0625 second period 
    // Timer Limit :: Timer counts up to 4 ticks |-> 1 second period
    // TODO: Consider implementing alternation in timer interrupt to double blinking period
    //        --> halving frequency of blinks

    /// Additional Timer Interrupts
      // * NOTE * CCRx cannot exceed CCR0 for MC__UP

    /// CRR1 used for LCD Display Ticker
    TA0CCTL1 = CCIE; // TAxCCR1 interrupt enabled
    TA0CCR1 = 31250; // Timer 0 CCR1
}

// Timer interrupt service routine
#pragma vector = TIMER0_A0_VECTOR   // Set Compiler to note to Vector (Memory Address for TimerA0)
__interrupt void TIMERA_TIMER_OVERFLOW_ISR(void){  // Question on overflow datatype  /// Set interrupt error handler to respond when vector above is initiated with interrupt routine.
//  mc_critical_tasks();
    P3OUT ^= 0x80;  // Production Build  /// MCU_Clock_on
    __bic_SR_register_on_exit(LPM4_bits);
}

  /// Pin Tutorial Below ///

    // P1OUT ^= 0x02; // Toggle P1.1
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

  alternatively     0x01 ^ 0x01 = 0x00
  0b00000001  
 ^0b00000001
 =0b00000000
    and             0x02 ^ 0x03 = 0x01
  0b00000010
 ^0b00000011
 =0b00000001
  */

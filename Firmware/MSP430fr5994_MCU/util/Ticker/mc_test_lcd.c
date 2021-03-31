#include "mc_test_lcd.h"
#include "stdio.h"

void testLCD(){
    
    /// Test Board Build
    // P3DIR |= 0xFF;      // Enables all pins on Port 3 as LCD Output Port
    // P8DIR |= 0x01;      // Enables LCD ENABLE PIN
    // P7DIR |= 0x1C;      // Enables LCD RS, RW, & B

    // P3OUT &= ~0xFF;     // Below sets all pins to LOW
    // P8OUT &= ~0x01;
    // P7OUT &= ~0x1C;

    /// Production Build
    /// p8.0 --> HIGH

    // IF YOU SWAP TO BOTTOM, CHANGE RESPECTIVE LINES IN hd44780.h 
    //    // (128 & 301)  <P3OUT vs P4OUT>

    P4DIR |= 0xFF;      // Enables all pins on Port 4 as LCD Output Port
    P8DIR |= 0x01;      // Enables LCD ENABLE PIN
    P7DIR |= 0x1C;      // Enables LCD RS, RW, & B

    P4OUT &= ~0xFF;     // Below sets all pins to LOW
    P7OUT &= 0x10;
    P7OUT |= 0x04;
    // P7OUT |= 0x8C;

    // __bis_SR_register( GIE );                            // Enable global interrupts
    hd44780_clear_screen();                             // Clear display content
    // hd44780_timer_isr();
    hd44780_write_string( "HEC project!  ", 1, 1, NO_CR_LF );
    hd44780_timer_isr();
    // TA1CTL |= TAIE;
}
// Directive for timer interrupt
#pragma vector = TIMER0_A1_VECTOR
__interrupt void TIMERA1_TEST_TIMER_OVERFLOW_ISR( void ){ // Timer 0 A1 interrupt service
    switch(__even_in_range(TA0IV, TAIV__TAIFG)){
        case TAIV__NONE:   break;           // No interrupt
        case TAIV__TACCR1:
            // P1OUT ^= 0x01;
            P5OUT ^= 0x08;
            // hd44780_write_string( "HEC project!  ", 1, 1, NO_CR_LF );
            hd44780_timer_isr();
            break;           // CCR1
        case TAIV__TACCR2:
            // P1OUT ^= 0x03;
            break;           // CCR2 not used
        case TAIV__TACCR3: break;           // reserved
        case TAIV__TACCR4: break;           // reserved
        case TAIV__TACCR5: break;           // reserved
        case TAIV__TACCR6: break;           // reserved
        case TAIV__TAIFG:                   // overflow
            // P1OUT ^= 0x03;
            break;
        default: break;
    }
    // printf("SEE THESE");
    //   TB0CCR0 += 1000; 
    //   hd44780_timer_isr();
    //   P1OUT ^= 0x01;
    __bic_SR_register_on_exit(LPM4_bits);
}

int _system_pre_init( void ) // This function is called before anything else is done
{
    WDTCTL = (WDTPW | WDTHOLD); // Stop watchdog timer
    return 1; // Return 1
}

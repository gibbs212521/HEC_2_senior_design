#include "mc_ticker_init.h"
//#include <stdlib.h>
//#include <string.h>
#include <stdio.h>

// char * toArray(int number)
// {
//     int n = log10(number) + 1;
//     int i;
//     char *numberArray = calloc(n, sizeof(char));
//     for (i = n-1; i >= 0; --i, number /= 10)
//     {
//         numberArray[i] = (number % 10) + '0';
//     }
//     return numberArray;
// }

volatile char ticker_msg[17];

void set_LCD_ticker(){
    // Build LCD Ticker
    P4DIR |= 0xFF;      // Enables all pins on Port 4 as LCD Output Port
    P8DIR |= 0x01;      // Enables LCD ENABLE PIN
    P7DIR |= 0x1C;      // Enables LCD RS, RW, & B

    P4OUT &= ~0xFF;     // Below sets all pins to LOW
    P7OUT &= 0x10;
    P7OUT |= 0x04;    
    
    P8OUT = 0x01;   // LCD Enable (Auxiliary Chip)

    hd44780_clear_screen();
    ADC12CTL0 |= ADC12ENC | ADC12SC;    // Start sampling/conversion
    // __delay_cycles(1000);
    _no_operation();
/// 0.15375375375 ratio 2^11/96 = 0.512 V should 6.5039
    int valued = (int) ADC12MEM15;//ADC12MEM15;// / 0x1000; --> volts :. valued *
    // float float_valued = valued/187.5; // this is a lie!
    float float_valued = (2.5*valued)/4096; // this is a lie!
    int whole_valued = (int) float_valued;
    float_valued = (float_valued - whole_valued) * 1000;
    int fraction_valued = (int) float_valued;
    // char * str_val = toArray(valued);
    // char * msg_gained = ("%d V",&valued);
    char msg_gained[17];
    sprintf(msg_gained, "%d.%d Volts", whole_valued, fraction_valued);
    // hd44780_write_string(msg_gained, 1, 1, NO_CR_LF);
    return;
}


#pragma vector = TIMER0_A1_VECTOR
__interrupt void TIMERA1_TIMER_OVERFLOW_ISR( void ){ // Timer 0 A1 interrupt service
    if ((ADC12CTL1 & ADC12BUSY) == 0) { // if not already converting
        // P5OUT ^= 0x04;
        __delay_cycles(320);
        ADC12CTL0 |= ADC12SC;
    }
    switch(__even_in_range(TA0IV, TAIV__TAIFG)){
        case TAIV__NONE:   break;           // No interrupt
        case TAIV__TACCR1:
                //// test
            // hd44780_clear_screen();
            // ADC12CTL0 |= ADC12ENC | ADC12SC;    // Start sampling/conversion
            // __delay_cycles(1000);
            _no_operation();
        /// 0.15375375375 ratio 2^11/96 = 0.512 V should 6.5039
            int valued = (int) ADC12MEM15;//ADC12MEM15;// / 0x1000; --> volts :. valued *
            // float float_valued = valued/187.5; // this is a lie!
            float float_valued = (2.5*valued)/4096; // this is a lie!
            int whole_valued = (int) float_valued;
            float_valued = (float_valued - whole_valued) * 1000;
            int fraction_valued = (int) float_valued;
            // char * str_val = toArray(valued);
            // char * msg_gained = ("%d V",&valued);
            char msg_gained[17];
            sprintf(msg_gained, "%d.%d Volts", whole_valued, fraction_valued);
            if (ticker_msg != msg_gained){
//                sprintf(ticker_msg, msg_gained);
                hd44780_write_string(msg_gained, 1, 1, NO_CR_LF);
                P5OUT ^= 0x04;
            }
                //// test
            // P1OUT ^= 0x01;   // Test Board Build
            P5OUT ^= 0x08;      // Production Build
            hd44780_timer_isr();
            __bic_SR_register_on_exit(LPM4_bits);
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
    __bic_SR_register_on_exit(LPM4_bits);
}

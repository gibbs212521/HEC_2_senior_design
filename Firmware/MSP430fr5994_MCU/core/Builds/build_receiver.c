#include "build_receiver.h"

void buildReceiver(){
// //  P5DIR |= 0X03;
    // SDA CHARGER @ BIT6
    P1DIR |= 0x40;
    // P1OUT |= 0x40;
    // // SCL CHARGER @ BIT7
    P1DIR |= 0x80;
    // P1OUT |= 0x80;
    char str_ValueNameADC12[6] = "RX V: ";
    char str_ValueNameADC13[6] = "RX I: ";
}


#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector = ADC12_B_VECTOR
__interrupt void ADC12_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(ADC12_B_VECTOR))) ADC12_ISR (void)
#else
#error Compiler not supported!
#endif
{
    switch(__even_in_range(ADC12IV, ADC12IV__ADC12RDYIFG))
    {
        case ADC12IV__ADC12IFG3:            // Vector 18:  ADC12MEM3
            ADC12CTL0 &=~ADC12SC;                       // For sequence-of-Channels mode, ADC12SC must be cleared by software after each sequence to trigger another sequence
            ADC12Value = (ADC12MEM0 * 0.013535156); // V
            ADC13Value = (ADC12MEM1 *0.80566)-30; // mA
            ADC14Value = ADC12MEM2 *0.80566; //mV
            ADC15Value = ADC12MEM3 *0.80566; //mV
            if ((P3OUT & 0x80) == 0x80){
                P5OUT |= 0x08;  // turns on right most LED
            } else {
                P5OUT &= ~0x08; // turns off right most LED
            }
            __bic_SR_register_on_exit(LPM0_bits);
            break;
            default: break;
     }
}

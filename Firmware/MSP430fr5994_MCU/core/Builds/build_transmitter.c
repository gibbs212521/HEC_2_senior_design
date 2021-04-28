#include "build_transmitter.h"

void buildTransmitter(){
    // OSC ENABLE and WPT ENABLE --> Direction addressed
    P5DIR |= 0x03;  // Set Port 5 Direction to bits 0 & 1.
    // OSC ENABLE --> Permanently ON
    P5OUT |= 0x01; // Set Port 5 Bit 1 to High
    // SDA AUX @ BIT6
    P1DIR |= 0x40;
    // P1OUT |= 0x40;
    // SCL AUX @ BIT7
    P1DIR |= 0x80;
    // P1OUT |= 0x80;
    char str_ValueNameADC12[12] = "P7 Pin1: ";
    char str_ValueNameADC15[12] = "Vds [Vpk]: ";
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
            ADC12Value = (ADC12MEM0 +270) *0.081372;    // 310 is diode drop in counts * V peak detect
            if (ADC12Value <= 46) ADC12Value = 0;
            ADC13Value = ADC12MEM1 *0.8813721;          // V peak detect *0.813721
            ADC14Value = (ADC12MEM2 *0.805) -30;        //mV
            ADC15Value = (ADC12MEM3 *0.805) -30;        //mV
            if (ADC15Value <= -1) ADC15Value = 0;       // if (ADC12MEM0 >= 0x7ff)         // ADC12MEM0 = A1 > 0.5AVcc?
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

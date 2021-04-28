#include "pins.h"
#include "hd44780.h"


short _compile_transmitter_pins = 0x00;

short ConfigureADC12Pins(short build_transmitter){
    if (build_transmitter==0x01){
        // P1OUT |= 0x03;
        _compile_transmitter_pins = 0x01;
    }
    // WDTCTL = WDTPW | WDTHOLD;               // Stop WDT

    // GPIO Setup
                    // Configure P3.0 for ADC  (ADC12)
    P3SEL1 |= BIT0;
    P3SEL0 |= BIT0;
                    // Configure P3.1 for ADC  (ADC13)
    P3SEL1 |= BIT1;
    P3SEL0 |= BIT1;
                    // Configure P3.2 for ADC  (ADC14)
    P3SEL1 |= BIT2;
    P3SEL0 |= BIT2;
                    // Configure P3.3 for ADC  (ADC15)
    P3SEL1 |= BIT3;
    P3SEL0 |= BIT3;



    // Disable the GPIO power-on default high-impedance mode to activate
    // previously configured port settings
    // PM5CTL0 &= ~LOCKLPM5;

    

    // General ADC Configuration
    ADC12CTL0 = ADC12ON | ADC12MSC | ADC12SHT0_3; // Turn on ADC12, set sampling time
    ADC12CTL1 = ADC12SHP | ADC12CONSEQ_1;       // Use sampling timer, single sequence
    ADC12CTL2 |= ADC12RES_2;                     // 12-bit conversion results
                         // Use sampling timer
    // Enable ADC conv complete interrupt (ADC Pin 0-15)
    
    // Configure ADC12 and/or ADC13
    ADC12MCTL0 |= ADC12INCH_12;                 // A12 ADC input select
    ADC12MCTL1 |= ADC12INCH_13;                 // A13 ADC input select
    ADC12MCTL2 |= ADC12INCH_14;                 // A14 ADC input select
    ADC12MCTL3 |= ADC12EOS | ADC12INCH_15;     // A15 ADC input select
    ADC12IER0 |= ADC12IE3;                     // Enable ADC conv complete interrupt @ ADC12MEM3
	ADC12CTL0 |= ADC12ENC;                    // Enable conversions
    return 0;
}
int filtFIR1(int s){
    int sum;
    int i;
   for (i = 0; i< 9; i++){
       FIR1samples[i+1] = FIR1samples[i]; //move samples
       sum += FIR1samples[i]; //add past samples
    }
    sum += s; //add current sample
    FIR1samples[0] = s;
    return (sum/10);
}

int filtFIR2(int s){
    int sum;
    int i;
   for (i = 0; i< 9; i++){
       FIR2samples[i+1] = FIR2samples[i]; //move samples
       sum += FIR2samples[i]; //add past samples
    }
    sum += s; //add current sample
    FIR2samples[0] = s;
    return (sum/10);
}

// #if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
// #pragma vector = ADC12_B_VECTOR
// __interrupt void ADC12_ISR(void)
// #elif defined(__GNUC__)
// void __attribute__ ((interrupt(ADC12_B_VECTOR))) ADC12_ISR (void)
// #else
// #error Compiler not supported!
// #endif
// {
//     switch(__even_in_range(ADC12IV, ADC12IV__ADC12RDYIFG))
//     {
//         case ADC12IV__NONE:        break;   // Vector  0:  No interrupt
//         case ADC12IV__ADC12OVIFG:  break;   // Vector  2:  ADC12MEMx Overflow
//         case ADC12IV__ADC12TOVIFG: break;   // Vector  4:  Conversion time overflow
//         case ADC12IV__ADC12HIIFG:  break;   // Vector  6:  ADC12BHI
//         case ADC12IV__ADC12LOIFG:  break;   // Vector  8:  ADC12BLO
//         case ADC12IV__ADC12INIFG:  break;   // Vector 10:  ADC12BIN
//         case ADC12IV__ADC12IFG0:   break;   // Vector 12:  ADC12MEM0 Interrupt
//         case ADC12IV__ADC12IFG1:   break;   // Vector 14:  ADC12MEM1
//         case ADC12IV__ADC12IFG2:   break;   // Vector 16:  ADC12MEM2
//         case ADC12IV__ADC12IFG3:            // Vector 18:  ADC12MEM3
//             ADC12CTL0 &=~ADC12SC;                       // For sequence-of-Channels mode, ADC12SC must be cleared by software after each sequence to trigger another sequence
//             ADC12Value = (ADC12MEM0 +270) *0.081372;    // 310 is diode drop in counts * V peak detect
//             if (ADC12Value <= 46) ADC12Value = 0;
//             ADC13Value = ADC12MEM1 *0.8813721;          // V peak detect *0.813721
//             ADC14Value = (ADC12MEM2 *0.805) -30;        //mV
//             ADC15Value = (ADC12MEM3 *0.805) -30;        //mV
//             if (ADC15Value <= -1) ADC15Value = 0;       // if (ADC12MEM0 >= 0x7ff)         // ADC12MEM0 = A1 > 0.5AVcc?
//             __bic_SR_register_on_exit(LPM0_bits);
//             break;
//         case ADC12IV__ADC12IFG4:   break;   // Vector 20:  ADC12MEM4
//         case ADC12IV__ADC12IFG5:   break;   // Vector 22:  ADC12MEM5
//         case ADC12IV__ADC12IFG6:   break;   // Vector 24:  ADC12MEM6
//         case ADC12IV__ADC12IFG7:   break;   // Vector 26:  ADC12MEM7
//         case ADC12IV__ADC12IFG8:   break;   // Vector 28:  ADC12MEM8
//         case ADC12IV__ADC12IFG9:   break;   // Vector 30:  ADC12MEM9
//         case ADC12IV__ADC12IFG10:  break;   // Vector 32:  ADC12MEM10
//         case ADC12IV__ADC12IFG11:  break;   // Vector 34:  ADC12MEM11
//         case ADC12IV__ADC12IFG12:  break;   // Vector 36:  ADC12MEM12
//         case ADC12IV__ADC12IFG13:  break;   // Vector 38:  ADC12MEM13
//         case ADC12IV__ADC12IFG14:  break;   // Vector 40:  ADC12MEM14
//         case ADC12IV__ADC12IFG15:  break;   // Vector 42:  ADC12MEM15
//         case ADC12IV__ADC12IFG16:  break;   // Vector 44:  ADC12MEM16
//         case ADC12IV__ADC12IFG17:  break;   // Vector 46:  ADC12MEM17
//         case ADC12IV__ADC12IFG18:  break;   // Vector 48:  ADC12MEM18
//         case ADC12IV__ADC12IFG19:  break;   // Vector 50:  ADC12MEM19
//         case ADC12IV__ADC12IFG20:  break;   // Vector 52:  ADC12MEM20
//         case ADC12IV__ADC12IFG21:  break;   // Vector 54:  ADC12MEM21
//         case ADC12IV__ADC12IFG22:  break;   // Vector 56:  ADC12MEM22
//         case ADC12IV__ADC12IFG23:  break;   // Vector 58:  ADC12MEM23
//         case ADC12IV__ADC12IFG24:  break;   // Vector 60:  ADC12MEM24
//         case ADC12IV__ADC12IFG25:  break;   // Vector 62:  ADC12MEM25
//         case ADC12IV__ADC12IFG26:  break;   // Vector 64:  ADC12MEM26
//         case ADC12IV__ADC12IFG27:  break;   // Vector 66:  ADC12MEM27
//         case ADC12IV__ADC12IFG28:  break;   // Vector 68:  ADC12MEM28
//         case ADC12IV__ADC12IFG29:  break;   // Vector 70:  ADC12MEM29
//         case ADC12IV__ADC12IFG30:  break;   // Vector 72:  ADC12MEM30
//         case ADC12IV__ADC12IFG31:  break;   // Vector 74:  ADC12MEM31
//         case ADC12IV__ADC12RDYIFG: break;   // Vector 76:  ADC12RDY
//         default: break;
//      }
//     __bic_SR_register_on_exit(LPM4_bits);
//     // ADC12CTL0 &= ~ADC12ENC;
//     // ADC12CTL0 &= ~ADC12ON;
//     // ADC12IER0 = 0x00;
// }



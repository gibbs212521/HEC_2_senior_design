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
    ADC12CTL0 &= ~ADC12ENC;
    ADC12CTL0 = ADC12ON | ADC12SHT0_4; //ADC12SHT0_3;      // Sampling time, S&H=16, ADC12 on
    ADC12CTL1 = ADC12CONSEQ_1 | ADC12SHP | ADC12SSEL_3 | ADC12VRSEL_14;                   // Use sampling timer
    ADC12CTL2 |= ADC12RES_2;//ADC12RES_1;//ADC12RES_2;                // 12-bit conversion results
    ADC12CTL3 |= ADC12CSTARTADD__ADC12MEM12;
    // Enable ADC conv complete interrupt (ADC Pin 0-15)
    ADC12IER0 = ADC12IE0 | ADC12IE12 | ADC12IE13 | ADC12IE14 | ADC12IE15;
    
    // Configure ADC12 and/or ADC13
    ADC12MCTL12 = ADC12DF_0 | ADC12VRSEL2 | ADC12INCH_12;               // A12 ADC input select; Vref=AVCC
    ADC12MCTL13 = ADC12DF_0 | ADC12VRSEL2 | ADC12INCH_13;               // A13 ADC input select; Vref=AVCC
    ADC12MCTL14 = ADC12DF_0 | ADC12VRSEL2 | ADC12INCH_14;               // A14 ADC input select; Vref=AVCC
    ADC12MCTL15 = ADC12EOS | ADC12DF_0 | ADC12VRSEL2 | ADC12INCH_15;    // A15 ADC input select; Vref=AVCC

    // while (1)
    // {
    //     __delay_cycles(5000);
    //     ADC12CTL0 |= ADC12ENC | ADC12SC;    // Start sampling/conversion
    //     printf("The pin voltage is %d V \n", ADC12MEM0);

    //     __bis_SR_register(LPM0_bits | GIE); // LPM0, ADC12_ISR will force exit
    //     __no_operation();                   // For debugger
    // }

    return 0;
}

// use (_compile_transmitter_pins) in if logic to multi-build

void GetADC(){
    ADC12CTL0 |= ADC12ENC | ADC12SC;    // Start sampling/conversion
    // __delay_cycles(1000);
    _no_operation();
}

short GetADC_12(){
    GetADC();
    return ADC12MEM12;
}

short GetADC_13(){
    GetADC();
    return ADC12MEM13;
}
short GetADC_14(){
    GetADC();
    return ADC12MEM14;
}
short GetADC_15(){
    GetADC();
    return ADC12MEM15;
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
    ADC12CTL0 &= ~ADC12ENC;
    switch(__even_in_range(ADC12IV, ADC12IV__ADC12RDYIFG))
    {
        case ADC12IV__NONE:        break;   // Vector  0:  No interrupt
        case ADC12IV__ADC12OVIFG:  break;   // Vector  2:  ADC12MEMx Overflow
        case ADC12IV__ADC12TOVIFG: break;   // Vector  4:  Conversion time overflow
        case ADC12IV__ADC12HIIFG:  break;   // Vector  6:  ADC12BHI
        case ADC12IV__ADC12LOIFG:  break;   // Vector  8:  ADC12BLO
        case ADC12IV__ADC12INIFG:  break;   // Vector 10:  ADC12BIN
        case ADC12IV__ADC12IFG0:            // Vector 12:  ADC12MEM0 Interrupt
            // if (ADC12MEM0 >= 0x7ff)         // ADC12MEM0 = A1 > 0.5AVcc?
            //     P1OUT |= BIT0;              // P1.0 = 1
            // else
            //     P1OUT &= ~BIT0;             // P1.0 = 0

            //     // Exit from LPM0 and continue executing main
            //     __bic_SR_register_on_exit(LPM0_bits);
            // P5OUT ^= 0x04;
            __bic_SR_register_on_exit(LPM4_bits);
            break;
        case ADC12IV__ADC12IFG1:   break;   // Vector 14:  ADC12MEM1
        case ADC12IV__ADC12IFG2:   break;   // Vector 16:  ADC12MEM2
        case ADC12IV__ADC12IFG3:   break;   // Vector 18:  ADC12MEM3
        case ADC12IV__ADC12IFG4:   break;   // Vector 20:  ADC12MEM4
        case ADC12IV__ADC12IFG5:   break;   // Vector 22:  ADC12MEM5
        case ADC12IV__ADC12IFG6:   break;   // Vector 24:  ADC12MEM6
        case ADC12IV__ADC12IFG7:   break;   // Vector 26:  ADC12MEM7
        case ADC12IV__ADC12IFG8:   break;   // Vector 28:  ADC12MEM8
        case ADC12IV__ADC12IFG9:   break;   // Vector 30:  ADC12MEM9
        case ADC12IV__ADC12IFG10:  break;   // Vector 32:  ADC12MEM10
        case ADC12IV__ADC12IFG11:  break;   // Vector 34:  ADC12MEM11
        case ADC12IV__ADC12IFG12:  
            ADC12IER0 &= ~ADC12IE12;
            __bic_SR_register_on_exit(LPM4_bits);
            // P5OUT ^= 0x04;
            break;   // Vector 36:  ADC12MEM12
        case ADC12IV__ADC12IFG13:  
            ADC12IER0 &= ~ADC12IE13;
            __bic_SR_register_on_exit(LPM4_bits);
            break;   // Vector 38:  ADC12MEM13
        case ADC12IV__ADC12IFG14:  
            ADC12IER0 &= ~ADC12IE14;
            __bic_SR_register_on_exit(LPM4_bits);
            break;   // Vector 40:  ADC12MEM14
        case ADC12IV__ADC12IFG15:  
            ADC12IER0 &= ~ADC12IE15;
            _no_operation();
            int valued = (int) ADC12MEM15;//ADC12MEM15;// / 0x1000; --> volts :. valued *
            float float_valued = (2.5*valued)/4096; // this is a lie!
            int whole_valued = (int) float_valued;
            float_valued = (float_valued - whole_valued) * 1000;
            int fraction_valued = (int) float_valued;
            char msg_gained[17];
            sprintf(msg_gained, "%d.%d Volts", whole_valued, fraction_valued);
            hd44780_write_string(msg_gained, 1, 1, NO_CR_LF);
                //// test
            // P1OUT ^= 0x01;   // Test Board Build
            P5OUT ^= 0x08;      // Production Build
            hd44780_timer_isr();
            __bic_SR_register_on_exit(LPM4_bits);
            __bic_SR_register_on_exit(LPM4_bits);
            // P5OUT ^= 0x04;
            // ADC12CTL0 &= ~ADC12ON;
            // ADC12IER0 = 0x00;
            break;   // Vector 42:  ADC12MEM15
        case ADC12IV__ADC12IFG16:  break;   // Vector 44:  ADC12MEM16
        case ADC12IV__ADC12IFG17:  break;   // Vector 46:  ADC12MEM17
        case ADC12IV__ADC12IFG18:  break;   // Vector 48:  ADC12MEM18
        case ADC12IV__ADC12IFG19:  break;   // Vector 50:  ADC12MEM19
        case ADC12IV__ADC12IFG20:  break;   // Vector 52:  ADC12MEM20
        case ADC12IV__ADC12IFG21:  break;   // Vector 54:  ADC12MEM21
        case ADC12IV__ADC12IFG22:  break;   // Vector 56:  ADC12MEM22
        case ADC12IV__ADC12IFG23:  break;   // Vector 58:  ADC12MEM23
        case ADC12IV__ADC12IFG24:  break;   // Vector 60:  ADC12MEM24
        case ADC12IV__ADC12IFG25:  break;   // Vector 62:  ADC12MEM25
        case ADC12IV__ADC12IFG26:  break;   // Vector 64:  ADC12MEM26
        case ADC12IV__ADC12IFG27:  break;   // Vector 66:  ADC12MEM27
        case ADC12IV__ADC12IFG28:  break;   // Vector 68:  ADC12MEM28
        case ADC12IV__ADC12IFG29:  break;   // Vector 70:  ADC12MEM29
        case ADC12IV__ADC12IFG30:  break;   // Vector 72:  ADC12MEM30
        case ADC12IV__ADC12IFG31:  break;   // Vector 74:  ADC12MEM31
        case ADC12IV__ADC12RDYIFG: break;   // Vector 76:  ADC12RDY
        default: break;
     }
    __bic_SR_register_on_exit(LPM4_bits);
    // ADC12CTL0 &= ~ADC12ENC;
    // ADC12CTL0 &= ~ADC12ON;
    // ADC12IER0 = 0x00;
}



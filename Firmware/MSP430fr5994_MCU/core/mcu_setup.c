#include "mcu_setup.h"

#ifdef COMPILE_TRANSMITTER
short BUILDING_TRANSMITTER = 1;
#endif
#ifndef COMPILE_TRANSMITTER
short BUILDING_TRANSMITTER = 0;
#endif

#ifdef RUN_TESTS
short RUN_MCU_TESTS = 1;
#endif
#ifndef RUN_TESTS
short RUN_MCU_TESTS = 0;
#endif

short mc_setup(){
    WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5; // power mode 5 control register 0 locks LPM5 bit
    reset_pins();
    
/// General Build
     ConfigureADC12Pins(BUILDING_TRANSMITTER); // ADC SENSORS
    set_button_interrupts(BUILDING_TRANSMITTER);
    main_clock_interrupt();
    // __enable_interrupt();
    set_LCD_ticker();

    if ( RUN_MCU_TESTS == 1 ) {
        return runTests(BUILDING_TRANSMITTER);
    }

/// TO-DO: We need to integrate interrupts by grade / priority levels.

/// PUT AUXILIARY CODE BELOW



/// PUT AUXILIARY CODE ABOVE

    return 0;
}

void reset_pins(){
    /// Resets all pins to 0x00 (PxDIR and PxOUT) to prevent bugs
    /// AND Sets pins based on transmitter or receiver being built.

    
    P1DIR = 0x00;
    P2DIR = 0x00;
    P3DIR = 0x00;
    P4DIR = 0x00;
    P5DIR = 0x00;
    P6DIR = 0x00;
    P7DIR = 0x00;

    P1OUT = 0x00;
    P2OUT = 0x00;
    P3OUT = 0x00;
    P4OUT = 0x00;
    P5OUT = 0x00;
    P6OUT = 0x00;
    P7OUT = 0x00;

    /// Production Build
    P3DIR |= 0x80;  // MCU_Clock_on LED  
    P5DIR |= 0x0C;  // LED 0 & LED 1
    P8DIR = 0x01;   // LCD Enable (Auxiliary Chip)

    /// Test Board Build
//    P1DIR |= 0x03;    // LED Green & LED Red

    if ( BUILDING_TRANSMITTER == 1 ) {
        buildTransmitter();
    } else {
        buildReceiver();
    };

}

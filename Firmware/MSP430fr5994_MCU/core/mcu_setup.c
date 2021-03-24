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

    // P3DIR |= 0x80;
    


    if ( BUILDING_TRANSMITTER == 1 ) {
        buildTransmitter();
   } else {
        buildReceiver();
   };
    if ( RUN_MCU_TESTS == 1 ) {
//        return runTests(BUILDING_TRANSMITTER);
   }

/// General Build
    ConfigureADC12Pins(BUILDING_TRANSMITTER); // ADC SENSORS
    set_button_interrupts(BUILDING_TRANSMITTER);
    // setUpLCD();
    main_clock_interrupt();

    // runTests(BUILDING_TRANSMITTER);

/// TO-DO: We need to integrate interrupts by grade / priority levels.

/// PUT AUXILIARY CODE BELOW



/// PUT AUXILIARY CODE ABOVE

    return 0;
}


#include "mcu_setup.h"


short mc_setup(){
    WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5; // power mode 5 control register 0 locks LPM5 bit

    short BUILDING_TRANSMITTER = 1;
    short RUN_MCU_TESTS = 0;

    if ( BUILDING_TRANSMITTER == 1 ) {
        buildTransmitter();
   } else {
        buildReceiver();
   };

    if ( RUN_MCU_TESTS == 1 ){
        return runTests(BUILDING_TRANSMITTER);
    };

//    setUpLCD();
//    GetVoltage();
//    main_clock_interrupt();
//    set_button_interrupts();  /// <-- Requires a test-board suite before reimplementing & a method to check for test board

/// TO-DO: We need to integrate interrupts by grade / priority levels.

    return 0;
}


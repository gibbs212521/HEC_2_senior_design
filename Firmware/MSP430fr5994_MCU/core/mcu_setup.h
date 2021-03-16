#ifndef __MC_MSP430_H
#define __MC_MSP430_H
#include <msp430fr5994.h>
#endif


#ifndef __MC_SETUP_H
#define __MC_SETUP_H


// #include "Pins/pins.h"
#include <ctype.h>

#ifndef COMPILE_TRANSMITTER
// #define COMPILE_TRANSMITTER  /// COMMENT TO BUILD RECEIVER
#include "Builds/build_receiver.h"
#include "Builds/build_transmitter.h"
#include "Interrupts/clock_interrupt.h"
#include "Interrupts/button_interrupt.h"
#endif

#include "mc_tests.h"


short mc_setup();
// short GetVoltage();


#endif

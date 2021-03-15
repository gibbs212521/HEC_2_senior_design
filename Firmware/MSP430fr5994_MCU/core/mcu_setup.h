#ifndef __MC_MSP430_H
#define __MC_MSP430_H
#include <msp430fr5994.h>
#endif

#ifndef __MC_SETUP_H
#define __MC_SETUP_H

#define COMPILE_TRANSMITTER

// #include "Interrupts/clock_interrupt.h"
// #include "Interrupts/button_interrupt.h"
// #include "Pins/pins.h"
#include <ctype.h>
#include "Builds/build_receiver.h"
#include "Builds/build_transmitter.h"
#include "mc_tests.h"

short mc_setup();
// short GetVoltage();

#endif

#ifndef __MC_MSP430_H
#define __MC_MSP430_H
#include <msp430fr5994.h>
#endif

#ifndef __MC_SETUP_H
#define __MC_SETUP_H

#include "Interrupts/clock_interrupt.h"
#include "Interrupts/button_interrupt.h"
#include "Pins/pins.h"
#include "../util/Ticker/mc_test_lcd.h"


short mc_setup();
short GetVoltage();

#define _BUILDING_TRANSMITTER_ 1;

#endif

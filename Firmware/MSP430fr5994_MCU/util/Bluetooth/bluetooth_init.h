#ifndef __MC_MSP430_H
#define __MC_MSP430_H
#include <msp430fr5994.h>
#endif

#ifndef __MC_BLUETOOTH_INIT_H
#define __MC_BLUETOOTH_INIT_H

short mc_bluetooth_is_connected();
void mc_bluetooth_reset();
void mc_bluetooth_init(short * introit);

#endif

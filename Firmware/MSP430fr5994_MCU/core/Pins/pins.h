#ifndef MC_PINS_H
#define MC_PINS_H
#include <msp430fr5994.h>
#include <stdio.h>
#include <stdint.h>

short ConfigureADC12Pins(short build_transmitter);
void GetADC();
short GetADC_12();
short GetADC_13();
short GetADC_14();
short GetADC_15();
#endif

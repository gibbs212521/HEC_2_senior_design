#ifndef MC_PINS_H
#define MC_PINS_H
#include <msp430fr5994.h>
#include <stdio.h>
#include <stdint.h>

short ConfigureADC12Pins(short build_transmitter);
int FIR1samples[10];
int FIR2samples[10];
int ADC12Value;
int ADC13Value;
int ADC14Value;
int ADC15Value;
int filtADC12Value;
int filtADC15Value;
int filtFIR1(int s);
int filtFIR2(int s);

#endif

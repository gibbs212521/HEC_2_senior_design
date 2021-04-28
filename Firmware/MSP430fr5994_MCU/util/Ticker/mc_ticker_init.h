#ifndef __MC_TICKER_INIT_H
#define __MC_TICKER_INIT_H
#include "msp430fr5994.h"
#include "hd44780.h"
#include "string.h"

void set_LCD_ticker();
char str_ADC12Value[8];
char str_ADC13Value[8];
char str_ADC14Value[8];
char str_ADC15Value[8];
char str_ADCValue_Name[10];
char str_Combined[20];
char str_Power[8];
volatile unsigned char TXData;
volatile unsigned char RXData;

char str_Volts[4] = "V";
char str_MiliVolts[4] = "mV";
char str_MiliAmps[4] = "mA";
char str_Watts[4] = "W";
char str_ValueNamePWR[6] = "PWR: ";


#endif

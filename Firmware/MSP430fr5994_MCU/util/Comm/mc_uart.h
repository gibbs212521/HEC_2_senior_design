#ifndef __MC_MSP430_H
#define __MC_MSP430_H
#include <msp430fr5994.h>
#endif

#ifndef __MC_UART_H
#define __MC_UART_H
#include <stdio.h>
#include <ctype.h>
#include <string.h>
// #include <stdlib.h>

void send_string(char s[]);
void _UART_TX(char * tx_data);
void resetCommUART();

#endif

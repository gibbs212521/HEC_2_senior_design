#ifndef __MC_MSP430_H
#define __MC_MSP430_H
#include <msp430fr5994.h>
#endif

#ifndef __MC_BLUETOOTH_TRANS_H
#define __MC_BLUETOOTH_TRANS_H

void mc_bluetooth_transmit(char msg[5], int message_data);
void mc_bluetooth_transmit_on();
void mc_bluetooth_transmit_off();
void mc_bluetooth_transmit_error(int );
void mc_bluetooth_transmit_risk(int );

void mc_bluetooth_receive_stop(int );
void mc_bluetooth_receive_continue(int );

void mc_bluetooth_receive_fully_charged(int );

#endif

#ifndef __MC_MSP430_H
#define __MC_MSP430_H
#include <msp430fr5994.h>
#endif

#ifndef __MC_BLUETOOTH_RECV_H
#define __MC_BLUETOOTH_RECV_H

#include <string.h>

void mc_bluetooth_receive(char msg[5], int * message_data);
void mc_bluetooth_receive_on();
void mc_bluetooth_receive_off();
void mc_bluetooth_receive_error(int *);
void mc_bluetooth_receive_risk(int *);
void mc_bluetooth_receive_get_charge(int *);
void mc_bluetooth_receive_get_recharge_time(int *);
void mc_bluetooth_receive_define_distance(int *);
void mc_bluetooth_receive_define_angle(int *);

#endif

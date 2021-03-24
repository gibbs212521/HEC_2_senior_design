#ifndef __MC_MSP430_H
#define __MC_MSP430_H
#include <msp430fr5994.h>
#endif

#ifndef __MC_BLUETOOTH_RECV_H
#define __MC_BLUETOOTH_RECV_H

#include <string.h>

void mc_bluetooth_receive(char msg[5], short message_data);
void mc_bluetooth_receive_on();
void mc_bluetooth_receive_off();
void mc_bluetooth_receive_error(short);
void mc_bluetooth_receive_risk(short);
void mc_bluetooth_receive_get_charge(short);
void mc_bluetooth_receive_get_recharge_time(short);
void mc_bluetooth_receive_define_distance(short);
void mc_bluetooth_receive_define_angle(short);

#endif

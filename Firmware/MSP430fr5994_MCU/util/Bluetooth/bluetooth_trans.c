#include "bluetooth_trans.h"
#include <stdio.h>

// Both transmitter to receiver and transmitter to computer:

void mc_bluetooth_transmit(char msg[5], int message_data){
    printf("This should be running the bt-lte transmission routine");
}

void mc_bluetooth_transmit_on(){
    printf("The transmitter is on");
    char msg[5] = " ON ";
    mc_bluetooth_transmit(msg, 1);
}

void mc_bluetooth_transmit_off(){
    printf("The transmitter is off");
    char msg[5] = " OFF";
    mc_bluetooth_transmit(msg, 0);
}

void mc_bluetooth_transmit_error(int message_data){
    printf("There is an error");
    char msg[5] = "ERRO";
    mc_bluetooth_transmit(msg, message_data);
}

void mc_bluetooth_transmit_risk(int message_data){ // changed from "danger" to "risk"
    printf("There is a safety issue");
    char msg[5] = "RISK";
    mc_bluetooth_transmit(msg, message_data);
}

// Receiver to transmitter:

void mc_bluetooth_transmit_stop(int message_data){
    printf("Stop transmitter charging");
    char msg[5] = "STOP";
    mc_bluetooth_transmit(msg, message_data);
}

void mc_bluetooth_transmit_continue(int message_data){
    printf("Continue transmitter charging");
    char msg[5] = "CONT"; // other words for "continue"
    mc_bluetooth_transmit(msg, message_data);
}

// Receiver to computer:

void mc_bluetooth_transmit_fully_charged(int message_data){
    printf("Device fully charged");
    char msg[5] = "FULL";
    mc_bluetooth_transmit(msg, message_data);
}

/*

    Transmitter -> Receiver
    ON                      "Periodically Assert Transmitter is on"
    OFF
    ERROR
    DANGER


    Receiver -> Transmitter
    STOP                    "Stop Transmitter Charging"
    CONTINUE                "Continue Transmitter Charging"


    Transmitter --> Computer
    ON
    OFF
    ERROR
    DANGER


    Receiver --> Computer
    FULLY_CHARGED

*/


/*
    Computer --> Receiver
    OFF
    GET_CHARGE
    GET_RECHARGE_TIME
    DEFINE_DISTANCE
    DEFINE_ANGLE


    Computer --> Transmitter
    OFF
    OFF_LOCK                "Lock in off position until reset or until computer indicates otherwise"
    OFF_UNLOCK
    GET_RUNTIME             "Ask transmitter for period of time of continuous charging"
    
*/

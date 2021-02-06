#include "bluetooth_trans.h"
#include <stdio.h>


void mc_bluetooth_transmit(){
    printf("This should be running the bt-lte transmission routine");

    
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
}


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

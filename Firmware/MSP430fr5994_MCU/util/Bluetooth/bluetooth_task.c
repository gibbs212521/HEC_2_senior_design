#include "bluetooth_task.h"
#include <stdio.h>


void mc_bluetooth_task(short introit){
    /// This method 
        // mc_bluetooth_task should always be followed by the scheduler
        // TO-DO: Consider fully functionalizing this method by reading some register
        //        in place of passing a variable of length 1 byte.
    /*
        0 :: Init BT-LTE Task
        1 :: Run Connection Routine
        2 :: Send Transmission Routine
    */
    switch (introit)
    {
    case 0:
        printf("testing");
        short * pintroit = &introit;
        mc_bluetooth_init(pintroit);
        mc_bluetooth_task(introit);
        break;
    case 1:
        mc_bluetooth_connect();
        break;
    case 2:
        mc_bluetooth_transmit();
        break;
    
    default:
        break;
    }
}

#include "bluetooth_init.h"
#include <stdio.h>
#include <stdlib.h>

short mc_bluetooth_is_connected(){
    printf("This should check if bluetooth is currently connected to correct pairing device(s)");
    return 1;// TO-DO: flush out this method
        //  0 --> not connected
        //  1 --> connected
}

void mc_bluetooth_listen(){
    /// This method should use a switch function with various communicable commands
        // NOTE: be wary of dependency injection at this point.
    printf("This should be listening to and reacting to message received");
}

void mc_bluetooth_reset(){
    printf("This should be reseting bluetooth configurations");
}

void mc_bluetooth_init(short * pintroit){
    /// Pass by address manipulation of original variable
        // Functional Programming approach
    printf("This should be starting the bt-lte init routine");
    short connection_status = mc_bluetooth_is_connected();
    (connection_status == 1) ? (mc_bluetooth_listen()) : (mc_bluetooth_reset());
    *pintroit = connection_status;
    return;
}


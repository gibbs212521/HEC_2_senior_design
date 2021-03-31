#include <stdio.h>

void mc_set_comm(short *POWER_LEVEL){
    *POWER_LEVEL = 1;
    return;
}

void mc_comm_controller(){
    printf("THIS SHOULD TALK TO THE PAIR\n");
}

void mc_comm_local(){
    printf("THIS SHOULD TALK TO THE PAIR\n");
}

void mc_comm_gui(){
    printf("THIS SHOULD TALK TO THE PAIR\n");
}

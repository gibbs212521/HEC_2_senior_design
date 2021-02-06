#include "bluetooth_recv.h"
#include <stdio.h>

void mc_bluetooth_receive_on(){
    printf("Device is charging \n");
}

void mc_bluetooth_receive_off(){
    printf("Device is not charging \n");
}

void mc_bluetooth_receive_error(int * error){
    printf("There is an error \n");
}

void mc_bluetooth_receive_risk(int * risk){
    printf("There is a safety issue \n");
}

void mc_bluetooth_receive_get_charge(int * charge){
    printf("Device charge is %d %% \n", charge);
}

void mc_bluetooth_receive_get_recharge_time(int * time){
    printf("Device recharge time is %d minutes \n", time);
}

void mc_bluetooth_receive_define_distance(int * distance){
    printf("Device distance is %d cm \n", distance);
}

void mc_bluetooth_receive_define_angle(int * angle){
    printf("Device angle is %d degrees \n", angle);
}

void mc_bluetooth_receive(char msg[5], int * message_data){


           if (strcmp(msg, " ON ")){
               mc_bluetooth_receive_on();
           }
           else if (strcmp(msg, " OFF")){
               mc_bluetooth_receive_off();
           }
           else if (strcmp(msg, "ERRO")){
               mc_bluetooth_receive_error(message_data);
           }
           else if (strcmp(msg, "RISK")){
               mc_bluetooth_receive_risk(message_data);
           }
           else if (strcmp(msg, "PERC")){
               mc_bluetooth_receive_get_charge(message_data);
           }
           else if (strcmp(msg, "RECH")){
               mc_bluetooth_receive_get_recharge_time(message_data);
           }
           else if (strcmp(msg, "DIST")){
               mc_bluetooth_receive_define_distance(message_data);
           }
           else if (strcmp(msg, "ANGL")){
               mc_bluetooth_receive_define_angle(message_data);
           }
}




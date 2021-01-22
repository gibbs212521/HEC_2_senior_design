#include <stdio.h>

void mc_power_on(unsigned char *POWER_BIT){
    *POWER_BIT = 0b1;
    return;
}

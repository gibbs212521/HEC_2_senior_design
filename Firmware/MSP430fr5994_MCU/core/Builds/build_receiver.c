#include "build_receiver.h"

void buildReceiver(){
//  P5DIR |= 0X03;
    P5DIR |= 0x08;
    P1DIR |= 0x03;
}

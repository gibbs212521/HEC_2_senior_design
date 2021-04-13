#include "build_receiver.h"

void buildReceiver(){
// //  P5DIR |= 0X03;
    // SDA CHARGER @ BIT6
    P1DIR |= 0x40;
    // P1OUT |= 0x40;
    // // SCL CHARGER @ BIT7
    P1DIR |= 0x80;
    // P1OUT |= 0x80;
}

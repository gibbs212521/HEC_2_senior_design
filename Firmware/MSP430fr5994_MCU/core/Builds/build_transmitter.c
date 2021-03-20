#include "build_transmitter.h"

void buildTransmitter(){
    // OSC ENABLE and WPT ENABLE --> Direction addressed
    P5DIR |= 0x03;  // Set Port 5 Direction to bits 0 & 1.
    // OSC ENABLE --> Permanently ON
    P5OUT |= 0x01; // Set Port 5 Bit 1 to High
    // SDA AUX @ BIT6
    P1DIR |= 0x40;
    P1OUT |= 0x40;
    // SCL AUX @ BIT7
    P1DIR |= 0x80;
    P1OUT |= 0x80;

}

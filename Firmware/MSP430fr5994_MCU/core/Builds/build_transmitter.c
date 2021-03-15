#include "build_transmitter.h"

void buildTransmitter(){
    P5DIR = 0x03;  // Set Port 5 Direction to bits 0 & 1.
    P5OUT |= 0x01; // Set Port 5 Bit 1 to High
}

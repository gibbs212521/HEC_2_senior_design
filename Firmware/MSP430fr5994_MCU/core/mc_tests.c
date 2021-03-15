#include "mc_tests.h"

short runTests(short transmitter_built){
    short FAILURE = 0;

    testLCD();

    if (FAILURE == 1){
        return 1;
    };
    return 0;
}
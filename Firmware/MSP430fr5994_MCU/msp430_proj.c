#include <msp430fr5994.h>

#include "util/Scheduler/scheduler.h"
#include "core/mcu_setup.h"
//#include <msp430fr5994_mockup.h>
/// msp430fr5994_mockup.h should be used for testing without MSP430fr5994 MCU.

/// Due to msp430.h, renamed msp430.c to msp430_proj.c to avoid any relation between the this file and msp430.h.

short main(){
   mc_setup();
   // struct MCScheduler mc_scheduler;
   // buildScheduler(&mc_scheduler);


   /// TO-DO: Consider creating a main config struct from main program to contain / control all states in MCU.


//    for(;;) {
//       mc_scheduler.select_next_task(&mc_scheduler);
//       volatile unsigned int i;            // volatile to prevent optimization
// //       P1OUT ^= 0x03;                      // Toggle P1.0 using exclusive-OR
//       i =0x1000;                         // SW Delay via do-while loop
//       do i--;
//       while(i != 0);
//                                            // infinite for loop repeats to toggle off/on P1
//    }
   return 0;
}

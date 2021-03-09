#include <msp430fr5994.h>

#include "util/Scheduler/scheduler.h"
#include "core/mcu_setup.h"
//#include <msp430fr5994_mockup.h>
/// msp430fr5994_mockup.h should be used for testing without MSP430fr5994 MCU.

/// Due to msp430.h, renamed msp430.c to msp430_proj.c to avoid any relation between the this file and msp430.h.

short main(){
   mc_setup();
   struct MCScheduler mc_scheduler;
   buildScheduler(&mc_scheduler);
   // mc_scheduler.check_shutdown_interrupt = SOME_SHUTDOWN_INTERRUPT
   // mc_scheduler.check_button_interrupt = SOME_BUTTON_INTERRUPT
   // mc_scheduler.check_timer_interrupt = SOME_TIMER_INTERRUPT
   mc_scheduler.runMC(&mc_scheduler);

   return 0;
}

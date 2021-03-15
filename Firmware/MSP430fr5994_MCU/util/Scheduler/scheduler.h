#ifndef __MC_MSP430_H
#define __MC_MSP430_H
#include <msp430fr5994.h>
#endif

#ifndef __MC_SCHEDULER_H
#define __MC_SCHEDULER_H

#include "../Bluetooth/bluetooth_task.h"
#include "../Ticker/lcd_task.h"
#include "../Power/power_task.h"
#include "../Comm/comm_protocol.h"


#define __BLUETOOTH_TASK__ 0x00
#define __LCD_TASK__ 0x01
#define __POWER_TASK__ 0x02
#define __CONTROLLER_COMM_TASK__ 0x03
#define __LOCAL_COMM_TASK__ 0x04
#define __GUI_COMM_TASK__ 0x05
#define __STATUS_CHECK_TASK__ 0x06
#define __AUX_TASK__ 0x07
#define __BUTTON_INTERRUPT_ 0x0C
#define __TIMER_INTERRUPT_ 0x0D
#define __SHUTDOWN_INTERRUPT_ 0x0E
#define __NO_TASK__  0x0F
#define __NUM_OF_TASKS__  0x09

struct MCScheduler{
    short __shutdown__;
    short current_task;
    short last_task;
    short next_task;
    short task_value[8];
    short bluetooth_introit;
    char base_task_name[21];
    char * task_name;
    // Function Pointers
    // method names must be functionNameLikeThis()
    void (*set_current_task)(struct MCScheduler *, short);
    void (*set_last_task)(struct MCScheduler *, short);
    void (*set_next_task)(struct MCScheduler *, short);
    void (*set_task_string)(struct MCScheduler *, short);
    void (*adjust_task_value)(struct MCScheduler *, short, short);
    void (*select_next_task)(struct MCScheduler *);
    short (*get_current_task)(struct MCScheduler *);
    short (*get_last_task)(struct MCScheduler *);
    short (*get_next_task)(struct MCScheduler *);
    // void (*check_timer_interrupt)();
    // void (*check_button_interrupt)();
    // void (*check_shutdown_interrupt)(struct MCScheduler *);
    void (*runMC)(struct MCScheduler *);
    void (*runTask)(struct MCScheduler *);
    void (*statusCheck)(struct MCScheduler *);
};

void _set_next_task_(struct MCScheduler * self, short next_task);
void _set_last_task_(struct MCScheduler * self, short last_task);
void _set_current_task_(struct MCScheduler * self, short current_task);
void _set_task_string_(struct MCScheduler * self, short);
void _adjust_task_value_(struct MCScheduler * self, short task, short value);
void _select_next_task_(struct MCScheduler * self);
short _get_next_task_(struct MCScheduler * self);
short _get_last_task_(struct MCScheduler * self);
short _get_current_task_(struct MCScheduler * self);

void _run_micro_controller_(struct MCScheduler * self);
void _mc_status_check_(struct MCScheduler * self);

 
void buildScheduler(struct MCScheduler * self);

void _run_task_(struct MCScheduler * self);

#endif

#ifndef __MC_MSP430_H
#define __MC_MSP430_H
#include <msp430fr5994.h>
#endif

#ifndef __MC_SCHEDULER_H
#define __MC_SCHEDULER_H

#define __BLUETOOTH_TASK__ 0x00
#define __LCD_TASK__ 0x01
#define __BATTERY_CHARGING_TASK__ 0x02
#define __CONTROLLER_COMM_TASK__ 0x03
#define __LOCAL_COMM_TASK__ 0x04
#define __GUI_COMM_TASK__ 0x05
#define __STATUS_CHECK_TASK__ 0x06
#define __AUX_TASK__ 0x07
#define __NO_TASK__  0x0F
#define __NUM_OF_TASKS__  0x09

struct MCScheduler{
    short current_task;
    short last_task;
    short next_task;
    short task_value[9];
    // Function Pointers
    // method names must be functionNameLikeThis()
    void (*set_current_task)(struct MCScheduler *, short);
    void (*set_last_task)(struct MCScheduler *, short);
    void (*set_next_task)(struct MCScheduler *, short);
    void (*adjust_task_value)(struct MCScheduler *, short, short);
    void (*select_next_task)(struct MCScheduler *);
    short (*get_current_task)(struct MCScheduler *);
    short (*get_last_task)(struct MCScheduler *);
    short (*get_next_task)(struct MCScheduler *);
};

void _set_next_task_(struct MCScheduler * self, short next_task);
void _set_last_task_(struct MCScheduler * self, short last_task);
void _set_current_task_(struct MCScheduler * self, short current_task);
void _adjust_task_value_(struct MCScheduler* self, short task, short value);
void _select_next_task_(struct MCScheduler *self);
short _get_next_task_(struct MCScheduler * self);
short _get_last_task_(struct MCScheduler * self);
short _get_current_task_(struct MCScheduler * self);

 
void buildScheduler(struct MCScheduler * self);


#endif

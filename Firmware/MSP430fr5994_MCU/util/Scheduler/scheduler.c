#include "scheduler.h"


/// Set Functions
void _set_next_task_(struct MCScheduler* self, short next_task){
    self->next_task = next_task;
    return;
}
void _set_last_task_(struct MCScheduler* self, short last_task){
    self->last_task = last_task;
    return;
}
void _set_current_task_(struct MCScheduler* self, short current_task){
    self->current_task = current_task;
    return;
}
void _adjust_task_value_(struct MCScheduler* self, short task, short value){
    self->task_value[task] = value;
    return;
}

/// Get Functions
short _get_next_task_(struct MCScheduler * self){
    return self->next_task;
}
short _get_last_task_(struct MCScheduler * self){
    return self->last_task;
}
short _get_current_task_(struct MCScheduler * self){
    return self->current_task;
}

/// Allocation Functions

void _select_next_task_(struct MCScheduler *self){
    self->last_task = self->current_task;
    self->current_task = __NO_TASK__;
    self->task_value[self->last_task] -= __NUM_OF_TASKS__;
    short iterator;
    short sequential_task;
    short sequential_task_value=0;
    // Looping Through Tasks such that (iterator :: __TASK_VALUE__)  c.f. scheduler.h
    for(iterator=0;iterator<=9;iterator++){
        if(self->task_value[iterator] > sequential_task_value){
            sequential_task = iterator;
        }
        self->task_value[iterator] += 1;
    }
}
    
void buildScheduler(struct MCScheduler *self){
    short i, task_list[9]={10,8,9,7,6,5,3,2,1};
    for(i=0;i<=9;i++){
        self->task_value[i]=task_list[i];
    }
    /// Define Get Function Pointers
    self->get_current_task = _get_current_task_;
    self->get_last_task = _get_last_task_;
    self->get_next_task = _get_next_task_;
    /// Define Set Function Pointers
    self->set_current_task = _set_current_task_;
    self->set_last_task = _set_last_task_;
    self->set_next_task = _set_next_task_;
    self->adjust_task_value = _adjust_task_value_;
    self->select_next_task = _select_next_task_;
    /// Setting Variables
    self->set_current_task(self, __BLUETOOTH_TASK__);
    self->set_last_task(self, __NO_TASK__);
    self->set_next_task(self, __LCD_TASK__);
    return;
};

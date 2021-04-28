#include "scheduler.h"


/// Set Functions

void _set_task_string_(struct MCScheduler * self, short task_number){
    switch(task_number){
        case __BLUETOOTH_TASK__ :
            self->task_name = "BLUETOOTH TASK       ";
            break;
        case __LCD_TASK__ :
            self->task_name = "LCD TASK             ";
            break;
        case __POWER_TASK__ : 
            self->task_name = "CHARGING TASK        ";
            break;
        case __CONTROLLER_COMM_TASK__ : 
            self->task_name = "COMM CONTROLLER      ";
            break;
        case __LOCAL_COMM_TASK__ : 
            self->task_name = "COMM LOCAL DEVICE    ";
            break;
        case __GUI_COMM_TASK__ : 
            self->task_name = "COMM GUI             ";
            break;
        case __STATUS_CHECK_TASK__ : 
            self->task_name = "STATUS TASK          ";
            break;
        case __AUX_TASK__ : 
            self->task_name = "AUXILIARY TASK       ";
            break;
        case __BUTTON_INTERRUPT_ : 
            self->task_name = "BUTTON INTERRUPT     ";
            break;
        case __TIMER_INTERRUPT_ : 
            self->task_name = "TIMER INTERRUPT TASK ";
            break;
        case __SHUTDOWN_INTERRUPT_ : 
            self->task_name = "SHUTDOWN INTERRUPT   ";
            break;
        case __NO_TASK__ : 
            self->task_name = "NO TASK              ";
            break;
        default : 
            self->task_name = "ERROR TASK NOT FOUND ";
            break;
    } 
}

void _set_next_task_(struct MCScheduler * self, short next_task){
    self->next_task = next_task;
    return;
}
void _set_last_task_(struct MCScheduler * self, short last_task){
    self->last_task = last_task;
    return;
}
void _set_current_task_(struct MCScheduler * self, short current_task){
    self->current_task = current_task;
    self->set_task_string(self, current_task);
    return;
}
void _adjust_task_value_(struct MCScheduler * self, short task, short value){
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

void _mc_status_check_(struct MCScheduler * self){
    /// CHECK IMPORTANT REGISTERS
    if (0==1){
        self->__shutdown__ = 1;
    }
}

void __run_task__(struct MCScheduler * self){
    self->set_current_task(self, self->next_task);
    self->set_next_task(self, __NO_TASK__);
    switch(self->current_task){
        case __BLUETOOTH_TASK__ :
            mc_bluetooth_task(&self->bluetooth_introit);
            break;
        case __LCD_TASK__ :
            mc_lcd_task();
            break;
        case __POWER_TASK__ : 
            mc_power_task();
            break;
        case __CONTROLLER_COMM_TASK__ :
            mc_comm_controller();
            break;
        case __LOCAL_COMM_TASK__ :
            mc_comm_local();
            break;
        case __GUI_COMM_TASK__ : 
            mc_comm_gui();
            break;
        case __STATUS_CHECK_TASK__ : 
            self->statusCheck(self);
            break;
        case __AUX_TASK__ : 
            /// I don't know what do here ??;
            break;
        case __BUTTON_INTERRUPT_ : 
            // self->check_button_interrupt();
            break;
        case __TIMER_INTERRUPT_ : 
            // self->check_timer_interrupt();
            break;
        case __SHUTDOWN_INTERRUPT_ : 
            // self->check_shutdown_interrupt(self);
            break;
        case __NO_TASK__ : 
            // printf("There is no task running... sorry mate \n");
            break;
        default :
            // printf("Some error is occuring\n");
            break;
    } 
}

void _run_micro_controller_(struct MCScheduler * self){
    for(;;){
            /// EMERGENCY SHUT TX OFF ///
        #ifdef COMPILE_TRANSMITTER
        // OSC ENABLE disabled if unsafe to transfer power
        if (filtADC12Value < 72){
            P5OUT |= 0x01;  // OFF
        } else {
            P5OUT &= ~0x01; // ON
        }
        #endif
            /// Regular Schedular ///
        // Check for Interrupt
        __bis_SR_register(LPM4_bits + GIE );    // Enable global interrupts
        // UCA0IE ^= UCRXIE     // Toggle USCI_A0 RX interrupt Enable Bit
        __no_operation();
        self->select_next_task(self);
        // self->check_shutdown_interrupt(self);
        // self->check_timer_interrupt();
        // self->check_button_interrupt();
        self->runTask(self);
        if(self->__shutdown__ == 1)
            break;
        
    }
}

/// Allocation Functions

void _select_next_task_(struct MCScheduler *self){
    self->set_last_task(self, self->current_task);
    // self->set_current_task(self, __NO_TASK__);
    // printf(" %d   \n", *self->task_value);
    self->task_value[self->last_task] -= __NUM_OF_TASKS__;
    short iterator = 0;
    short sequential_task;
    short sequential_task_value=0;
    // Looping Through Tasks such that (iterator :: __TASK_VALUE__)  c.f. scheduler.h
    for(iterator=0;iterator<=__NUM_OF_TASKS__;iterator++){
        if(self->task_value[iterator] > sequential_task_value){
            sequential_task = iterator-1;
        }
        self->task_value[iterator] += 1;
        // printf(" seq. task  %d   \n", sequential_task);
        // printf(" task value %d   \n", sequential_task_value);
        // printf(" iterator   %d   \n", iterator);
    }
    self->set_task_string(self, sequential_task);
    // printf("\n Your Next Task is %s   \n", self->task_name);
    _set_next_task_(self, sequential_task);
}
    
void buildScheduler(struct MCScheduler * self){
    self->task_name = self->base_task_name;
    self->__shutdown__ = 0;
    short i, task_list[8]={9,7,8,6,4,5,3,2};
    for(i=0;i<=__NUM_OF_TASKS__;i++){
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
    self->set_task_string = _set_task_string_;
    self->runTask = __run_task__;
    self->runMC = _run_micro_controller_;
    self->statusCheck = _mc_status_check_;
    /// Setting Variables
    self->set_current_task(self, __BLUETOOTH_TASK__);
    self->set_last_task(self, __NO_TASK__);
    self->set_next_task(self, __LCD_TASK__);
    resetCommUART();
    UCA0TXBUF = 'A';
    return;
}

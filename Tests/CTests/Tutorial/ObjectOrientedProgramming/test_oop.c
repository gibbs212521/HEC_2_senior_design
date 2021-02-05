#include <stdio.h>
#include "test_oop.h"

struct Test{
    int value;
    void (*set)(struct Test *, int);
};

void setter(struct Test * self, int value){
    self->value = value;
}

struct Test createTestItem(void){
    struct Test tested;
    tested.value = 50;
    printf("\n\n%d\n",tested.value);
    tested.set=setter;
    tested.set(&tested,250);
    printf("%d\n",tested.value);
    return tested;
}

int main(){
    struct MCScheduler mc_scheduler;
    buildScheduler(&mc_scheduler);
    printf("Scheduler data: %d\n", mc_scheduler.next_task);
    printf("Scheduler data: %d\n", __LCD_TASK__);
    struct Test t1;
    t1 = createTestItem();
    printf("\n\n%d\n",t1.value);
    t1.set(&t1,150);
    printf("%d\n",t1.value);
    return 0;
}

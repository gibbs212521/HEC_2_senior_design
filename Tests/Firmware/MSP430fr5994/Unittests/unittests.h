#ifndef _MC_UNITTESTS_H
#define _MC_UNITTESTS_H

#include "test_structs.h"

struct TestStruct{
    char name[20];
    char state[1];
    int test_number;

    int * getOnes;
    int * getTens;
    int * getHundreds;
    int * getThousands;

    void * setName;
    void * setFunction;
    void * setComparator;
    void * setTestNumber;
};


int PullOnes(struct TestStruct * self);
int PullTens(struct TestStruct * self);
int PullHundreds(struct TestStruct * self);
int PullThousands(struct TestStruct * self);
struct TestStruct BuildTestStruct(struct TestStruct * self);

void RunTest(int * test_num, int * test_func, int * test_comparison);

#endif

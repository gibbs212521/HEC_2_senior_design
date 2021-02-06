#ifndef _MC_UNITTESTS_H
#define _MC_UNITTESTS_H

#include <stdio.h>
#include <math.h>

int GetOnes(int number);
int GetTens(int number);
int GetHundreds(int number);
int GetThousands(int number);

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

struct TestStruct BuildTestStruct(struct TestStruct * self);

void RunTest(int * test_num, int * test_func, int * test_comparison);

#endif

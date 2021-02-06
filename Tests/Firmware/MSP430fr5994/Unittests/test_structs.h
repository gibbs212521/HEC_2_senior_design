#ifndef _MC_TEST_STRUCTS_H
#define _MC_TEST_STRUCTS_H

#include <stdio.h>
#include <math.h>

int _GetOnes_(int number);
int _GetTens_(int number);
int _GetHundreds_(int number);
int _GetThousands_(int number);

struct TestStruct{
    char _test_name_[20];
    char * test_name;
    int state;
    int test_number;

    int (*getOnes)(struct TestStruct *);
    int (*getTens)(struct TestStruct *);
    int (*getHundreds)(struct TestStruct *);
    int (*getThousands)(struct TestStruct *);

    void (*setTestName)(struct TestStruct *, char);
    void (*setTestNumber)(struct TestStruct *, int);
    void (*incrementTestNumber)(struct TestStruct *);

    void (*setFunctionVoid)(struct TestStruct *);
    void (*setFunctionInt)(struct TestStruct *, int *, int);
    void (*setFunctionShort)(struct TestStruct *, short *, short);
    void (*setFunctionChar)(struct TestStruct *, char *, const char*);
    void (*setFunctionFloat)(struct TestStruct *, float *, float);

};


int _PullOnes_(struct TestStruct *);
int _PullTens_(struct TestStruct *);
int _PullHundreds_(struct TestStruct *);
int _PullThousands_(struct TestStruct *);
void _SetTestName_(struct TestStruct *, char *);


struct TestStruct BuildTestStruct(struct TestStruct *);

#endif

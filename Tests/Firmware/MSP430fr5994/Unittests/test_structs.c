#include "test_structs.h"

int _GetOnes_(int number){
    return number % 10;
}
int _GetTens_(int number){
    return ((number - _GetOnes_(number))/10)%10;
}
int _GetHundreds_(int number){
    return ((number - _GetOnes_(number) - _GetTens_(number))/100)%10;
}
int _GetThousands_(int number){
    return ((number - _GetOnes_(number) - _GetTens_(number - _GetHundreds_(number)))/1000)%10;
}


int _PullOnes_(struct TestStruct * self){
    int number = self->test_number;
    return _GetOnes_(number);
}
int _PullTens_(struct TestStruct * self){
    int number = self->test_number;
    return _GetTens_(number);
}
int _PullHundreds_(struct TestStruct * self){
    int number = self->test_number;
    return _GetHundreds_(number);
}
int _PullThousands_(struct TestStruct * self){
    int number = self->test_number;
    return _GetThousands_(number);
}

void _SetTestName_(struct TestStruct * self, char *name[20]){
    self->test_name = name;
}



struct TestStruct BuildTestStruct(struct TestStruct * self){
    self->test_name = self->_test_name_;
    self->getOnes = _PullOnes_;
    self->getTens = _PullTens_;
    self->getHundreds = _PullHundreds_;
    self->getThousands = _PullThousands_;
    self->test_number = 1;
    self->setTestName = _SetTestName_;
}

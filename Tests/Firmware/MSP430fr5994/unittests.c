#include "unittests.h"


int GetOnes(int number){
    return number % 10;
}
int GetTens(int number){
    return ((number - GetOnes(number))/10)%10;
}
int GetHundreds(int number){
    return ((number - GetOnes(number) - GetTens(number))/100)%10;
}
int GetThousands(int number){
    return ((number - GetOnes(number) - GetTens(number - GetHundreds(number)))/1000)%10;
}

struct TestStruct BuildTestStruct(struct TestStruct * self){

}

void RunTest(int * test_num, struct * test_struct){
    int ones, tens, hundreds, thousands;

    char test_number_str[5] = ("%d%d%d%d", &thousands, &hundreds, &tens, &ones);
    puts("\n**********Test Number %s", test_number_str);
    puts(" ");
}


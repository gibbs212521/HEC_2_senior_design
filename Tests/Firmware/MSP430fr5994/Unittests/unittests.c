#include <time.h>
#include "unittests.h"

void RunTest(struct TestStruct * test_struct){
    int ones = test_struct->getOnes(&test_struct);
    int tens = test_struct->getTens(&test_struct);
    int hundreds = test_struct->getHundreds(&test_struct);
    int thousands = test_struct->getThousands(&test_struct);

    char test_number_str[5] = ("%d%d%d%d", &thousands, &hundreds, &tens, &ones);
    puts("\n**********Test Number %s", test_number_str);
    puts(" ");
}


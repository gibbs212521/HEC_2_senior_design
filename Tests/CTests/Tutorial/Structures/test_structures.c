#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include ".\Headers\BuckysInfo.h" 


int main()
{
    struct user bucky;
    struct user emily;
    
    bucky.weight = 225; // "Dot Operator" used to access different items or members of structure
    bucky.userID = 1;
    emily.userID = 2;

    puts("Enter the first name of user 1");
    gets(bucky.firstname);
    puts("Enter the first name of user 2");
    gets(emily.firstname);
    
    printf("User 1 is : %s with User ID : %i\nUser 2 is : %s with User ID : %d \n", bucky.firstname, bucky.userID, emily.firstname, emily.userID);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


int main()
{
    int i = 0;

    while(i < 10){
        printf("i = %s%d\n", (i < 10) ? " ":"", ++i);
    }

    int day = 1;
    float quantity = 0.01;

    while(day <= 31){
        printf("Day:%d \t Amount:$%.2f \n", day++, quantity);
        quantity *= 2;
    }

    do{
        printf("1 == 0 if you read this twice. If only once, then 1 != 0 due to Do-While Loop.\n\n");
    }
    while(1 == 0);

    float sumOfGrades = 0, scoreEntered = 0, numberOfTests = 0, average = 0;

    printf("Press 0 when complete\n\n");

    do{
        printf("Test Score: %.0f \t Average:%2f\n", numberOfTests++, average);
        printf("\nEnter Test Score: ");
        scanf(" %f", &scoreEntered);
        sumOfGrades += scoreEntered;
        average = sumOfGrades / numberOfTests;
    }
    while(scoreEntered != 0);
    printf("\n\n");

    int bacon;

    for(bacon=1;bacon<=10;bacon++){
        printf("Behold bacon number %d\n", bacon);
    }
    printf("\n\n");
    for(bacon=0;bacon<=100;bacon+=8){
        printf("Behold bacon number %d\n", bacon);
    }

    int j, howManyIterations, maxIteration=10;

    printf("\nHow many times do you want this loop to loop? (up to 10) : ");
    scanf(" %d", &howManyIterations);
    for(j=1;j<=maxIteration;j++){
        if(j>howManyIterations){
            break;
        }
        printf("Iteration Number : %d\n", j);
        if(j==howManyIterations){
            break;
        }
    }

    int skipThisIteration;

    printf("\nWhich iteration do you wish to skip in the loop? (up to 10) : ");
    scanf(" %d", &howManyIterations);
    for(j=1;j<=maxIteration;j++){
        if(j==howManyIterations){
            continue;
        }
        printf("Iteration Number : %d\n", j);
    }

    return 0;
}

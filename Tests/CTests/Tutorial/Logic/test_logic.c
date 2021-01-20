#include <stdio.h>
#include <stdlib.h>

int main()
{
    if(4 < 10){
        printf("Four is less than 10.\n");
    }
    if(3 == 3){
        printf("Three is equivalent to three.\n");
    }
    if(3 != 4){
        printf("Three is not equivalent to four.\n");
    }
    int favorite_number;

    printf("What be ye favorite number?\n");
    scanf(" %d", &favorite_number);

    if(favorite_number > 21){
        printf("You make bad choices in numbers\n");
    }
    if(favorite_number < 5){
        printf("You should aim at higher numbers\n");
    }
    if(favorite_number == 7){
        printf("You have a good favorite number\n");
    }
    if(favorite_number != 7){
        printf("Next time, you should consider a different favorite number...\n");
        if(favorite_number > 7){
            printf("try a lower number next time\n");
        }
        if(favorite_number < 7){
            printf("try a higher number next time\n");
        }
    }

    int logic_assertion = 1;
    if(logic_assertion){
        printf("1 is equivalent to true\n");
    }
    else{
        printf("0 is equivalent to false\n");
    }

    float grade_1; float grade_2; float grade_3; float average;
    printf("Insert your last three grades\n");
    scanf(" %f", &grade_1);
    scanf(" %f", &grade_2);
    scanf(" %f", &grade_3);

    average = (grade_1 + grade_2 + grade_3) / 3;
    char avg_grade;
    printf("Your average is %f\n", average);
    if(average == 100){
        printf("You have no more potential\n");
    }
    if(average > 100){
        printf("You are a cheater, you get a zero for the class\n");
        avg_grade = 'F';
        grade_1 = grade_2 = grade_3 = 0;
    }
    else if(average >= 90){
        avg_grade = 'A';
    }
    else if(average >= 80){
        avg_grade = 'B';
    }
    else if(average >= 70){
        avg_grade = 'C';
    }
    else if(average >= 65){
        avg_grade = 'D';
    }
    else{
        avg_grade = 'F';
        printf("You are full of potential\n");
    }
    printf("Your average grade results in a %c for the class.\n", avg_grade);

    char answer;
    printf("Do you like bagels (y/n) \n");
    scanf(" %c", &answer);

    if( (answer=='y') || (answer=='n') ){ // utilization of OR command
        printf("Good job, you messed not up\n");
    }
    else{
        printf("You entered an invalid character.\n");
    }

    (5 > 1) ? printf("Five is greater than 1\n") : printf("Fivei s less than 1\n");

    int friends = 87;
    printf("I have %d friend%s\n", friends, (friends!=1) ? "s" : "");
    friends = 1;
    printf("I have %d true friend%s\n", friends, (friends!=1) ? "s" : "");


    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void printSomething();

int warts_global = 23; // Any function can use global functions such as this
//... including every file that includes the header file of the file

int main() 
{ 
    int age; 
    age = 29; 
    printf("Bucky is %d years old\n", age); 
    int new_age; 
    printf("integer declaration and assignment successful\n"); 
    new_age = 2021-1987; 
    printf("Bucky is %d years old\n", new_age); 
    printf("integer subtraction operation successful\n"); 
    int var_age; 
    int current_year; 
    int birthYear; 
    current_year = 2021; 
    birthYear = 1963; 
    var_age = current_year - birthYear; 
    printf("Bucky is %d years old\n", var_age); 
    printf("integer subtraction operation successful\n"); 

    int warts_local;
    warts_local = 5;
    printf("I have %d warts\n", warts_global);
    printSomething();

    return 0; 
} 


void printSomething(){ // void does not return any value
    int warts_local;
    warts_local = 15;
    printf("I have %d warts\n", warts_local);
    return;
}

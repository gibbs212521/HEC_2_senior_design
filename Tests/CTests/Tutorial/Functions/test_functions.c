#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include ".\Headers\BuckysInfo.h" 


/// Prototyping Functions
void printSomething();
void euroToDollar(float euro);
void dollartoEuro(float usd);
int calculateBonus(int yearsWorked);
void passByValue(int i);
void passByAddress(int * i);

int main() // main() is the primary function that must exist in a c / c++ program
{
    printSomething();
    float EuroPrice1 = 1.00;
    float EuroPrice2 = 5.50;

    euroToDollar(EuroPrice1);
    euroToDollar(EuroPrice2);
    euroToDollar(21.30);

    int buckysBonus, emmasBonus;
    buckysBonus = calculateBonus(14);
    emmasBonus = calculateBonus(3);
    printf("Bucky gets $%d \n", buckysBonus);
    printf("Emily gets $%d \n", emmasBonus);

    printf("\nOR directly\n\nBucky gets $%d \n", calculateBonus(14));
    printf("Emily gets $%d \n", calculateBonus(3));

    int tuna = 20;
    passByValue(tuna);
    printf("Tuna was 20, now it is : %d via Passing By Value\n", tuna);
    printf("Pass By Value does not pass variable itself\n");
    printf("This can be run for tests without affecting the variables in question\n");
    passByAddress(&tuna); // Remember to pass the pointer of the variable !!
    printf("Tuna was 20, now it is : %d via Passing By Address\n", tuna);
    printf("Pass By Address passes the variable itself, in essence\n");
    printf("This can be used with functional programming\n");

    return 0;
}


void printSomething(){ // void does not return any value
    printf("\ndumm dumm duuummmmm! I'm a function\n");
    return;
}

void euroToDollar(float euro){
    float ratio;
    ratio = 0.71;
    float usd = euro * ratio;
    printf("%.2f Euros = %.2f USD\n", euro, usd);
    return;
}

void dollartoEuro(float usd){
    float ratio;
    ratio = 1.37;
    float euro = usd * ratio;
    printf("%.2f USD = %.2f Euros\n", usd, euro);
    return;
}

int calculateBonus(int yearsWorked){
    int bonus = 0;
    bonus = yearsWorked * 250;
    if(yearsWorked > 10){
        bonus += 1000;
    }
    return bonus;
}

void passByValue(int i){
    i = 99;
    return;
}

void passByAddress(int * i){
    *i = 65;
    return;
}

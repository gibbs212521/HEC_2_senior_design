#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main()
{
    int tuna = 19;
    printf("%p ", &tuna); // %p refers to the pointer with the memory address of the datatype unit.
    printf("\n\nAddress \t Name \t Value \n");
    printf("%p \t %s \t %d \n", &tuna, "tuna", tuna);

    int * pTuna = &tuna;
    printf("%p \t %s \t %d \n", pTuna, "tuna", tuna);
    printf("%p \t %s \t %p \n", &pTuna, "pTuna", pTuna);

    printf("\n*pTuna: %d \n", *pTuna); // * before pointer --> dereferences a POINTER --> gets the value of a pointer
    // Prediction : We could use dereferencing of pointers to read the bit values in a particular register in a MCU.

    if (*pTuna == tuna){
        printf("A dereferenced pointer is equivalent to the object it points to.\n\n");
    }

    int i, meatBalls[5] = {7,9,43,21,3};
    
    printf("meatball \t pointer \t value\n");
    for(i=0;i<5;i++){
        printf("meatBalls[%d] \t %p \t %d \n", i, &meatBalls[i], meatBalls[i]);
    }
    printf("\nmeatBalls \t\t %p \n", meatBalls);
    printf("NOTICE: The array meatBalls is the pointer to the first element in the meatBalls array! Woah!\n");
    printf("ERGO: We may dereference it's value to get the first element value : %d == %d\n", *meatBalls, meatBalls[0]);
    printf("*(meatBalls+2) \t\t %d \n\n", *(meatBalls+2)); //shifts two registers down :: Move two elements deeper into the array.

    char movie1[] = "The Return of Buckyman"; // NOTE every string is a CONSTANT
//    movie1 = XXX; // you CANNOT change the value of the movie by assignment as it destroys the array
    char * movie2 = "Bucky Bee Awesome I Love Him!"; // NOTE not a constant but a POINTER VARIABLE

    puts(movie2); // takes pointer and reads out until it reaches null \0 (String Terminus Character)
    movie2 = "New Movie Hey!";
    puts(movie2);

    char movie[20];
    char * pMovie = movie;

    puts("Input your movie title.");
    fgets(pMovie, 20, stdin); // fgets here takes user input and cuts off input after 20 characters.. can be from file or from internet etc..
    puts(pMovie);



    return 0;
}
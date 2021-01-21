#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    // The heap is the left over memory that is not being used by your computer.
    // "It's like extra memory that you can borrow." - Bucky

    int * points; // integer point to first point on the heap

    points = (int *) malloc(5 * sizeof(int)); // malloc === Memory Allocation
    // (int *) int type cast pointer  --> used when storing int from the heap.
    free(points); // Allows returning of memory allocated before completion of program

    int i, howMany, total;
    float average = 0.0;
    int * pointsArray;

    printf("How many numbers do you want to average?\n");
    scanf(" %d", &howMany);

    pointsArray = (int *) malloc(howMany * sizeof(int)); // Expandable Array from heap
    
    printf("Enter them hoss! \n");
    for(i=0; i<howMany; i++){
        scanf(" %d", &pointsArray[i]);
        total += (float)pointsArray[i];
    }
    average = total / howMany;
    printf("Your average number is : %.2f \n", average);
    free(pointsArray);


    return 0;
}

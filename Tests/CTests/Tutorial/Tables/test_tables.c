#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


int main()
{
    int column, row;
    int numOfCols = 4, numOfRows = 6;

    for(row=1; row<=numOfRows; row++){
        printf(" %d : ", row);
        for(column=1; column<=numOfCols; column++){
            printf(" %d ", column);
        }
        printf("\n");
    }
    return 0;
}

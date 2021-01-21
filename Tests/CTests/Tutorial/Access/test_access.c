#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


int main()
{
    FILE * fPointer;
    fPointer = fopen("bacon.txt", "w+"); // w+ --> open for writing first but then permit reading afterwards
    fputs("I ate 3 pumpkins today", fPointer);
    
    fseek(fPointer, 7, SEEK_SET); // SEEK_SET means to start at the beginning of file sic SET Flip Flop --> 0
    fputs(" munchkins on Friday", fPointer);

    fseek(fPointer, -6, SEEK_END); // SEEK_END puts pointer at END OF FILE
    fputs("top of a mountain", fPointer);

    fclose(fPointer);
    return 0;
}
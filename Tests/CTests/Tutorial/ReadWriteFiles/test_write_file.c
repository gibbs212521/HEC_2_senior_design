#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


int main()
{
    // Sequential Files     -->     in order read / write
    // Random Access Files  -->     read / write order does not matter

    FILE * fPointer;    //  file pointer (frequently named fp)
    // mode keyword : w  --> write
    // mode keyword : r  --> read
    // mode keyword : a  --> append  "or add more crap" -Bucky
    fPointer = fopen("bacon.txt","w");
    fprintf(fPointer, "Bacon is good.\n"); // fprintf prints to file that begins with your file pointer
    // the data inserted into file is stored to computer and does not exist in RAM.
    // ERGO: Stable data is created.
    fclose(fPointer);

    return 0;
}
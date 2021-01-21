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
    fPointer = fopen("bacon.txt","a"); // append takes filepointer and puts to the end of the file
    fprintf(fPointer, "\n - Bucky Robertsham");
    fclose(fPointer);

    return 0;
}
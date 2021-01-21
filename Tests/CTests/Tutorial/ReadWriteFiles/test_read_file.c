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
    fPointer = fopen("bacon.txt","r");

    char singleLine[150];
    
    while(!feof(fPointer)){ // !feof === Not File End Of File  --> continues loop until end of file (EOF)
        fgets(singleLine, 150, fPointer);
        puts(singleLine); // NOTE: causes read of \n of .txt plus puts automatic \n at end of line.
    }

    fclose(fPointer);

    return 0;
}
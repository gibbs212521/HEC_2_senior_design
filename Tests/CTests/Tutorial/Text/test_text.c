#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main() 
{
printf("Hello World!"); 
printf("\nEnd Line Enacted \n\n"); 
printf("Audio Beep Enacted \a \n"); 
printf("Tabular Shift 'Tab' Enacted \t see \t these \t tabs \n"); 
printf("%s is a test for substitution %s\n", "THIS", "HERE"); 
printf("String replacement successful.\n"); 
printf("I ate %d corndogs last night... Thanks %s\n", 25, "Bucky"); 
printf("Integer, decimal replacement successful.\n"); 
printf("Pi is %f\n", 3.1415926535); 
printf("%d decimal places shown in float replacement\n", 6); 
printf("Pi is %.7f\n", 3.1415926535); 
printf("%d decimal places shown in float replacement\n", 7); 
printf("Pi is %.4f\n", 3.1415926535); 
printf("%d decimal places shown in float replacement\n", 4); 
char some_name[14] = "Bucky Roberts"; 
printf("The first letter of some name is %c\n", some_name[0]); 
printf("The Third letter of some name is %c\n", some_name[2]); 
printf("Some name is %s \n", some_name); 
some_name[2] = 'z'; 
printf("The third letter has changed, see %s\n", some_name); 
printf("The Third letter of some name has changed to %c\n", some_name[2]); 
char food[] = "tuna"; 
printf("This is the best food ever, %s.  It was assigned without defining its array size btw.\n", food); 
strcpy(food, "BACON!"); 
printf("This is the best food ever, %s.  It was assigned with the string copy (strcpy) command.\n", food); 

int tuna = 'b';
char lime = 'L';
char Lemon = 'l';
char snake= '8';
printf("\n\n TUNA is %d which is from int tuna = 'b'\n", tuna);
printf("toupper -> %c\n",toupper(Lemon));
printf("toupper -> %c with int value\n", toupper(tuna));
printf("tolower -> %c\n", tolower(lime));

char ham[100] = "Hey ";

strcat(ham, "Bucky ");
printf("%s. You concatenated your name with strcat(var, \"str\")! \n", ham);
strcat(ham, "you ");
strcat(ham, "smell!\n");
printf("%s", ham);

strcpy(ham, "Bucky is Awesome!\n");
printf("%s", ham);

printf("%p is the address in 0x (Hex) format with %%p.\n", &tuna);
printf("%p is item in 0x (Hex) format with %%p.\n", tuna);
printf("0123456789\n0123456789\rabcd\n");
printf("NOTICE how \\r returns the cursor to the begining of its line \n\
    and that abcd then overwrites characters in the character array.\n");

//  \n      insert new-line
//  \r      insert carriage return (Return to column 0 of current line in text) --> generally reserved for windows .txt and .csv
//  \a      OS Alert Beep
//  \t      insert tab
//  \d      inline integer (decimal) substitution
//  \f      inline float substitution
//  \.3f    inline float substitution w/ precision of 3
//  \c      inline character substitution
//  \s      inline string substitution
//  \p      inline 0x (Hex) substitution --> used for pointers / memory addresses

return 0; 
} 

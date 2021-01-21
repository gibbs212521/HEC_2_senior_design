#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char string_var[20];
    char string_var_2[20];
    int integer_var;

    printf("What is your input string?\n");
    scanf(" %s", string_var);
    printf("Testing string var %s\n\n", string_var);

    printf("What is your second input string?\n");
    scanf(" %s", string_var_2);
    printf("Testing string var2 %s\n\n", string_var_2);

    printf("What is your integer input?\n");
    scanf(" %d", &integer_var); // Remember that non-char arrays require an explicit pointer to assign values.
    printf("Testing integer variable %d\n\n", integer_var);

    printf("You shall %s and %s without %d ????\n", string_var, string_var_2, integer_var);

    // must clear console input before transitioning from scanf to gets function via fflush(stdin) command.
    fflush(stdin);

    char catsName[50];
    char catsFood[25];
    char sentence[75] = "";

    // puts, unlike scanf, will accept the total line until the use presses enter/return line

    puts("\nWhat is the cat's name? ");
    gets(catsName);

    puts("\nWhats does the cat eat? ");
    gets(catsFood);

    strcat(sentence, catsName);
    strcat(sentence, " LOVES to eat ");
    strcat(sentence, catsFood);
    strcat(sentence, " and indeed he does.");

    puts(sentence);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char string_var[20];
    char string_var_2[20];
    int integer_var;

    printf("What is your input string?\n");
    scanf("%s", string_var);
    printf("Testing string var %s\n\n", string_var);

    printf("What is your second input string?\n");
    scanf("%s", string_var_2);
    printf("Testing string var2 %s\n\n", string_var_2);

    printf("What is your integer input?\n");
    scanf("%d", &integer_var); // Remember that non-char arrays require an explicit pointer to assign values.
    printf("Testing integer variable %d\n\n", integer_var);

    printf("You shall %s and %s without %d ????\n", string_var, string_var_2, integer_var);

    return 0;
}

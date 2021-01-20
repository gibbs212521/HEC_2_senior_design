#include <stdio.h>
#include <stdlib.h>

int main()
{
    int weight = 285; // all weight in pounds (lbs)
    int watermelon_weight = 5;
    float float_weight = 285.3;
    float float_watermellon_weight = 4.62;

    printf("modulus of weight %% watermelon: %d\n", weight % watermelon_weight);
    printf("division of weight / watermelon as an integer: %d\n", weight / watermelon_weight);
    printf("modulus does not operate with float variables.\n");
    printf("float division of weight / watermelon as a float: %f\n", float_weight / float_watermellon_weight);
    // Remember PEMDOS for order of operations in math operations.  This tutorial will not explore this.

    // Simultaneous variable assignment
    int a; int b; int c;

    a = b = c = 100;

    printf("Testing simultaneous variable assignment a, b, c, :: %d, %d, %d\n", a, b, c);
    // Incrementals
    int views=0;
    views += 1;
    printf("You're seeing this %d time\n", views);
    views += 1;
    printf("You're seeing this %d times\n", views);
    views += 1;
    printf("You're seeing this %d times\n", views);
    views += 1;
    printf("You're seeing this %d times\n", views);

    float balance = 1000.00;
    
    balance *= 1.1;
    printf("Balance : $%.2f\n", balance);
    balance *= 1.1;
    printf("Balance : $%.2f\n", balance);
    balance *= 1.1;
    printf("Balance : $%.2f\n", balance);
    balance *= 1.1;
    printf("Balance : $%.2f\n", balance);

    float avgProfit;
    int priceOfPumpkin = 10;
    int sales = 59;
    int daysWorked = 7;

    avgProfit = (priceOfPumpkin * sales) / daysWorked;
    printf("int vs float conflict with average daily profit $%.2f\n", avgProfit);
    avgProfit = ((float)priceOfPumpkin * sales) / daysWorked; // temporary type casting int into float for priceOfPumpkin variable 
        //--> forcing all operations to be done as flaots
    printf("True average daily profit $%.2f\n", avgProfit);

    int tested = 5;
    printf("test value : %d\n",tested);
    printf("test++ value : %d\n",tested++);
    printf("test value : %d\n",tested);
    printf("Notice that +1 increment was place after the value is read\n");
    printf("++test value : %d\n",++tested);
    printf("Notice that +1 increment was place before the value is read\n");
    printf("test value : %d\n",tested);
    printf("test-- value : %d\n",tested--);
    printf("test value : %d\n",tested);
    printf("--test value : %d\n",--tested);
    printf("test value : %d\n",tested);

    a = 5, b = 10;
    int answer;
    answer = ++a * b;
    printf("Answer from ++a * b : %d \n", answer);
    
    a = 5, b = 10, answer = 0;
    answer = a++ * b;
    printf("Answer from a++ * b : %d \n", answer);
    
        

    return 0;
}
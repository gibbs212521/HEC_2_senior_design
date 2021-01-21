#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main(){

    int i;
    int meatBalls[5], totalBalls = 0;
    float averageBalls;

    for(i=0; i<5; i++){
        printf("How many Meatballs did you eat on day %d? :  ", i+1);
        scanf(" %d", &meatBalls[i]);
    }
    
    for(i=0; i<5; i++){
        printf(" Element %d : %d\n", i, meatBalls[i]);
        totalBalls += meatBalls[i];
    }
    averageBalls += (float)totalBalls / 5;
    printf("Average number of meatballs consumed by you : %.2f\n", averageBalls);

    int counter, player[5] = {58, 66, 68, 71, 87};
    int goals[5] = {26, 39, 25, 29, 31};
    int gamesPlayed[5] = {30, 30, 28, 30, 26};
    float ppg[5], bestPPG = 0;
    int bestPlayer;

    printf("Player \t Goals  \t Games \t PPG\n");
    for(counter=0;counter<5;counter++){
        ppg[counter] = (float)goals[counter]/gamesPlayed[counter];
        printf("%d \t %d \t %d \t %.2f \n", player[counter], goals[counter], gamesPlayed[counter], ppg[counter]);
        if(ppg[counter] > bestPPG){
            bestPPG = ppg[counter];
            bestPlayer = player[counter];
        }
    }
    printf("Player %d is the best bet! He has %.2f points per game!\n", bestPlayer, bestPPG);

    // Sorting Arrays
    int b, temp, swapped;
    int howMany = 10;
    int scores[howMany]; // IDE wants constants instead of variables.

    for(b=0;b<howMany;b++){
        scores[b] = (rand() % 25)+1;
    }
    printf("\n\nOriginal List\n");
    for(b=0;b<howMany;b++){
        printf("%d \n", scores[b]);
    }

    // infinite loop with breakout logic
    while(1){
        swapped = 0;
        for(i=0; i<howMany-1; i++){
            if(scores[i]>scores[i+1]){
                temp = scores[i];
                scores[i] = scores[i+1];
                scores[i+1] = temp;
                swapped = 1;
            }
        }
        if(swapped == 0){
            break;
        }
    }
    
    printf("\n\nSorted List\n");
    for(b=0;b<howMany;b++){
        printf("%d \n", scores[b]);
    }

    return 0;
}

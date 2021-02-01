#include <stdio.h>
#include <stdlib.h>

void mc_write_ticker(char *TICKER[18]){
//    int * pTicker_txt = 0x{Txt_Address};
//    char ticker_txt[18] = *pTicker;
    char ticker_txt[18] = {"THIS IS A TEST"};
    printf("ticker is written to");
    *TICKER = ticker_txt;
    return;
}

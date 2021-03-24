/// TODO 
/*

USE A GLOBAL STRING (tx_msg)
  +  define it with one function
  +  send in another function with a delay
  +  cycle it in read interrupt if rx_char_in == tx_char_out
  +  stop at end of read interrupt
  -
  +  If no transmission exists --> echo characters read to tx_char_out
  +  

    __LOOK INTO__
    o Concept of how only 1 byte is transmitted at any moment over UART.
        -> Have algorithm with specialized ACK - *** *** *** Terms 
            so to communicate with UART in a standard fashion.

*/
///

#include "mc_uart.h"

volatile unsigned short tx_indx;
volatile char tx_msg[30];
volatile unsigned short rx_indx = 0;
volatile char rx_msg[30];

void UART_TX(char * tx_data){               // Define a function which accepts a character pointer to an array
    unsigned int i=0;
    while(tx_data[i] != '\0'){                     // Increment through array, look for null pointer (0) at end of string
        while ((UCA3STATW & UCBUSY));                 // Wait if line TX/RX module is busy with data
            UCA0TXBUF = tx_data[i];                                // Send out element i of tx_data array on UART bus
        i++;                                                                   // Increment variable for array address
    }
}

void resetCommUART(){
    // Set P2.0 and P2.1 for USCI_A0 UART operation
    printf("\n\n Resetting UART Settings \n\n");
    P2SEL0 &= ~(BIT0 | BIT1);
    P2SEL1 |= BIT0 | BIT1;
    
    // Startup clock system with max DCO setting ~1MHz /// (not) ~8MHz
    CSCTL0_H = CSKEY >> 8;                // Unlock clock registers
    CSCTL1 = DCOFSEL_3 | DCORSEL;         // Set DCO to 1MHz (DCOFSSEL_0) /// 8 MHz (DC0FSEL_3)
    CSCTL2 = SELA__VLOCLK | SELS__DCOCLK | SELM__DCOCLK;
    CSCTL3 = DIVA__1 | DIVS__1 | DIVM__1; // Set all dividers
    CSCTL0_H = 0;                         // Lock CS registers

    // Configure USCI_A0 for UART mode
    UCA0CTLW0 = UCSWRST;          // enable software reset
    UCA0CTLW0 |= UCSSEL__SMCLK;   // CLK = SMCLK

    // Baud Rate calculation
    // 8000000/(16*9600) = 52.083
    // Fractional portion = 0.083
    // UCBRFx = int ( (52.083-52)*16) = 1
    UCA0BR0 = 52;                 // 8000000/16/9600
    UCA0BR1 = 0x00;
    UCA0MCTLW |= UCOS16 | UCBRF_1 | 0x4900;

    UCA0CTLW0 &= ~UCSWRST;        // Initialize eUSCI, disable software reset
    UCA0IE |= UCRXIE;             // Enable USCI_A0 RX interrupt
}

  #pragma vector=USCI_A0_VECTOR
  __interrupt void USCI_A0_ISR(void){
      printf("interrupt discovered\n");
      switch(__even_in_range(UCA0IV, USCI_UART_UCTXCPTIFG))
      {
          case USCI_NONE:
              break;
          case USCI_UART_UCRXIFG:
                printf("interrupt discovered USCI_UART_UCRXIFG\n");
                // printf("\n TESTING... %s\n", UCA0RXBUF);
                rx_msg[rx_indx] = UCA0RXBUF;
                printf("\n TEST THIS STR %s\n", rx_msg);
                if (rx_indx >= 30){
                    rx_indx = 0;
                }
                rx_indx++;
                UCA0TXBUF = (unsigned short) UCA0RXBUF + 1;        //echo
                __no_operation();
                // P1OUT ^= BIT0;               //LED P1.0 switched off
                // __no_operation();
                break;
          case USCI_UART_UCTXIFG:
              printf("interrupt discovered USCI_UART_UCTXIFG\n");
              break;
          case USCI_UART_UCSTTIFG:
              break;
          case USCI_UART_UCTXCPTIFG:
              break;
      }
 }

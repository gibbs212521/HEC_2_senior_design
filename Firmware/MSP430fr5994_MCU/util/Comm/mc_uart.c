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


void send_string(char s[])
{
    int i =0;
    while (s[i] != 0x00)
    {
        while(!(UCA0IFG & UCTXIFG));
        UCA0TXBUF = s[i];
        i++;
    }
    while(!(UCA0IFG & UCTXIFG));
    UCA0TXBUF = 0x0d; //CR
    while(!(UCA0IFG & UCTXIFG));
    UCA0TXBUF = 0x0a; //LF
}

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
    P2SEL0 &= ~(BIT0 | BIT1);
    P2SEL1 |= BIT0 | BIT1;
    
    // Configure USCI_A0 for UART mode
    UCA0CTLW0 = UCSWRST;          // enable software reset
    UCA0CTLW0 |= UCSSEL__SMCLK;   // CLK = SMCLK

    // Baud Rate calculation    //// NOTE: DCOFSEL8 -> less fractional loss
    // 8000000/(16*9600) = 52.083
    // Fractional portion = 0.083
    // UCBRFx = int ( (52.083-52)*16) = 1
    UCA0BR0 = 52; // 8000000/16/9600;
    UCA0BR1 = 0x00;
    UCA0MCTLW |= UCOS16 | UCBRF_8 | 0x4900;
    UCA0CTLW0 &= ~UCSWRST;        // Initialize eUSCI, disable software reset
    UCA0IE |= UCRXIE;             // Enable USCI_A0 RX interrupt

    // Configure USCI_A1 for UART mode BT module 115kHz Baud rate no flow control
    UCA1CTLW0 = UCSWRST;                    // Put eUSCI in reset
    UCA1CTLW0 |= UCSSEL__SMCLK;             // CLK = SMCLK
    UCA1BRW = 8;                            // 1000000/115200 = 8.68
    UCA1MCTLW = 0xD600;                     // 1000000/115200 - INT(1000000/115200)=0.68
                                            // UCBRSx value = 0xD6 (See UG)
    UCA1CTLW0 &= ~UCSWRST;                  // release from reset
    UCA1IE |= UCRXIE;                       // Enable USCI_A1 RX interrupt

}

  #pragma vector=USCI_A0_VECTOR
  __interrupt void USCI_A0_ISR(void){
    //   printf("interrupt discovered\n");
    switch(__even_in_range(UCA0IV, USCI_UART_UCTXCPTIFG))
    {
        case USCI_NONE:
            break;
        case USCI_UART_UCRXIFG:
            rx_msg[rx_indx] = UCA0RXBUF;
            if (rx_indx >= 30){
                rx_indx = 0;
            }
            rx_indx++;
            UCA0TXBUF = (unsigned short) UCA0RXBUF + 1;        //echo
            __no_operation();
            break;
        case USCI_UART_UCTXIFG:
            break;
        case USCI_UART_UCSTTIFG:
            break;
        case USCI_UART_UCTXCPTIFG:
            break;
    }
 }

#include "uart.h"

#define UART0DR_BASE  0x101f1000
#define UART0DR  *((volatile unsigned int * const )((unsigned int *)(UART0DR_BASE)))
void Uart_send_String(unsigned char * ptr_tx_string)
{
    while(* ptr_tx_string !=0)
    {
        UART0DR = (unsigned int) (* ptr_tx_string);
        ptr_tx_string++ ;
    }

}
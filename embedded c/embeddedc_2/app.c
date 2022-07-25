 #include "uart.h"


unsigned char string_name[100] = "Learn-in-depth\n";


void main(void)
{

	Uart_send_String(string_name);
}
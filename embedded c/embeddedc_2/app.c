 #include "uart.h"


unsigned char string_name[100] = "Learn-in-depth : ahmed";

unsigned char const moh[100]="create_row_data_section";

void main(void)
{

	Uart_send_String(string_name);
}
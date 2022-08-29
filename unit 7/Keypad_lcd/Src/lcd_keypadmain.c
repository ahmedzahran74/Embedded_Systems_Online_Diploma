/*
 * lcd_keypadmain.c
 *
 *  Created on: Aug 28, 2022
 *      Author: AM
 */
#include "LCD.h"
#include "Keypad.h"
void delay_ms(uint32_t time);
void clock_init()
{
	//enable clock for GPIO port a & GPIO port b
	RCC_GPIO_PORTA_CLK_EN();
	RCC_GPIO_PORTB_CLK_EN();
}
int main(void)
{
	clock_init();
	LCD_INIT();
	LCD_WRITE_STRING("HEY...");
	delay_ms(500);
	LCD_clear_screen();
	unsigned char LCD_DISPLAY [11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
	for (unsigned char i = 0; i < 11; i++) {
		LCD_WRITE_CHAR(LCD_DISPLAY[i]);
		delay_ms(100);
	}
	LCD_clear_screen();
	Keypad_init();
	LCD_WRITE_STRING("Keypad is ready");
	delay_ms(50);
	LCD_clear_screen();
	volatile char KEY;
	volatile int count=0;
	while(1)
	{

		KEY=Keypad_getkey();
		switch(KEY)
		{
		case'!':LCD_clear_screen();break;
		case'N':break;
		default:
			if(count<16){
				LCD_WRITE_CHAR(KEY);
				count++;
			}
			else
			{
				count=0;
				LCD_clear_screen();
				LCD_WRITE_CHAR(KEY);
			}
			break;

		}
		}
}





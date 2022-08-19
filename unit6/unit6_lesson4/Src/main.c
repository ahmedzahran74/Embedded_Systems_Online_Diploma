/*
 * main.c
 *
 *  Created on: Aug 18, 2022
 *      Author: AM
 */
#include "app_trigger.h"
#include "GPIO.h"
void system_init(void);
int main(void)
{
	system_init();
	App_1();
	while(1);
}
void system_init(void)
{
	GPIO_init();
	EXTI_init();
}

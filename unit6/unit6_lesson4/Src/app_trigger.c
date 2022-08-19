/*
 * app_trigger.c
 *
 *  Created on: Aug 18, 2022
 *      Author: AM
 */

#include "app_trigger.h"
#include "GPIO.h"

void Assign_GPIO_ISR_Fun(void(*ptr)(void))
{
	EXTI0_ISR=ptr;
}
void GPIO_ISR_Fun(void)
{
	//Toggle pin 13 port A
	GPIO_ODR^=(1<<13);
	//clear pending request
	EXTI_PR|=(1<<0);
}
void App_1(void)
{
	Assign_GPIO_ISR_Fun(GPIO_ISR_Fun);

}

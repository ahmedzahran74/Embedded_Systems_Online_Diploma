/*
 * app_trigger.c
 *
 *  Created on: Aug 18, 2022
 *      Author: AM
 */

#include "app_trigger.h"
#include "GPIO.h"


void GPIOA_ISR_Fun(void)
{
	//Toggle pin 13 port A
	GPIOA_ODR^=(1<<13);
	//clear pending request
}
void App_1(void)
{
	Assign_GPIOA_ISR_Fun(GPIOA_ISR_Fun);

}

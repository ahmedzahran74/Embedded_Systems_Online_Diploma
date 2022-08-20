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
	int i=0;


	while(1)
	{
		//check if PA1 connected external PUR
		if((GPIOA_IDR&(1<<1))>>1==0)//multi press
		{
			do
			{
				GPIOB_ODR^=1<<1;

				for(i=0;i<1000;i++);
			}while((GPIOA_IDR&(1<<1))>>1==0);
		}
		//check if PA13 connected external PDR
		if((GPIOA_IDR&(1<<13))>>13==1)//single press
		{
				GPIOB_ODR^=1<<13;
				while((GPIOA_IDR&(1<<13))>>13==1);
		}
	}
}
void system_init(void)
{
	GPIOA_init();
}

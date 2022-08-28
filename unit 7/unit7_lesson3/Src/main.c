/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
#include "STM32f103c6_GPIO.h"
#include "useful_macros.h"

void system_init();
int main(void)
{
	system_init();
	int i=0;

	while(1)
	{
		//check if PA1 connected external GND
		if(MCAL_GPIO_Read_Pin(GPIO_PORTA,GPIO_PIN_1)==0)//multi press
		{
			do
			{
				MCAL_GPIO_TogglePin(GPIO_PORTB,GPIO_PIN_1);
				//GPIOB_ODR^=1<<1;

				for(i=0;i<1000;i++);
			}while(MCAL_GPIO_Read_Pin(GPIO_PORTA,GPIO_PIN_1)==0);
		}
		//check if PA13 connected to Vcc
		if(MCAL_GPIO_Read_Pin(GPIO_PORTA,GPIO_PIN_13)==1)//single press
		{
			MCAL_GPIO_TogglePin(GPIO_PORTB,GPIO_PIN_13);
			//GPIOB_ODR^=1<<13;
			while(MCAL_GPIO_Read_Pin(GPIO_PORTA,13)==1);
		}
	}
	/* Loop forever */
	for(;;);
}
void system_init()
{
	//enable clock for GPIO port a & GPIO port b

	RCC_GPIO_PORTA_CLK_EN();
	RCC_GPIO_PORTB_CLK_EN();

	//define configuration structures
	GPIO_pin_configue_t portA_pin1,portA_pin13,portB_pin1,portB_pin13;

	//initialize GPIO port A pin 1 structure

	portA_pin1.GPIO_pin_mode=GPIO_MODE_INPUT;
	portA_pin1.GPIO_pin_CNF=GPIO_IN_FLOATING;
	portA_pin1.GPIO_pin_number=GPIO_PIN_1;


	//initialize GPIOA port pin 13 structure

	portA_pin13.GPIO_pin_mode=GPIO_MODE_INPUT;
	portA_pin13.GPIO_pin_CNF=GPIO_IN_FLOATING;
	portA_pin13.GPIO_pin_number=GPIO_PIN_13;


	////initialize GPIOB port pin 1 structure

	portB_pin1.GPIO_pin_mode=GPIO_MODE_OUTPUT_10M;
	portB_pin1.GPIO_pin_CNF=GPIO_OUT_PUSHPULL;
	portB_pin1.GPIO_pin_number=GPIO_PIN_1;


	////initialize GPIOB port pin 13 structure

	portB_pin13.GPIO_pin_mode=GPIO_MODE_OUTPUT_10M;
	portB_pin13.GPIO_pin_CNF=GPIO_OUT_PUSHPULL;
	portB_pin13.GPIO_pin_number=GPIO_PIN_13;


	//configure GPIO portA pin 1 & GPIO portA pin 13 & GPIO portB pin 1 & GPIO portB pin 13
	MCAL_GPIO_Init(GPIO_PORTA, &portA_pin1);
	MCAL_GPIO_Init(GPIO_PORTA, &portA_pin13);
	MCAL_GPIO_Init(GPIO_PORTB, &portB_pin1);
	MCAL_GPIO_Init(GPIO_PORTB, &portB_pin13);





}

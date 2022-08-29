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
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "GPIO.h"
//RCC register address


void(*EXTI0_ISR)()=NULL;


void GPIO_init()
{
	//enable GPIOA clock
	RCC_APB2ENR|=(1<<2);
	//enable AFIO clock
	RCC_APB2ENR|=(1<<0);
	//configure pin 13 as an output
	GPIO_CRH&=0xFF0FFFFF;
	GPIO_CRH|=0x00200000;
	//configure pin 0 as an input
	GPIO_CRL&=0xFFFFFFFC;
	GPIO_CRL|=(1<<2);

}
void EXTI_init(void)
{
	//AFIO configuration

	AFIO_EXTICR1&=~(0xF);

	//Enable rising edge triggering
	EXTI_RTSR|=(1<<0);

	//enable interrupt mask register for line 0
	EXTI_IMR|=1<<0;

	//NVIC interrupt enable
	NVIC_ISER0|=(1<<6);
}
void EXTI0_IRQHandler(void)
{
	if (EXTI0_ISR!=NULL)
	{
		EXTI0_ISR();
	}
}
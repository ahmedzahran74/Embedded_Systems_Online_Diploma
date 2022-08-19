/*
 * GPIO.h
 *
 *  Created on: Aug 18, 2022
 *      Author: AM
 */

#ifndef GPIO_H_
#define GPIO_H_
#include <stdint.h>
#define RCC_BASE		0x40021000
#define RCC_APB2ENR		*(volatile uint32_t*)(RCC_BASE+0x18)
//GPIO register addresses
#define GPIO_BASE		0x40010800
#define GPIO_CRH		*(volatile uint32_t*)(GPIO_BASE+0x04)
#define GPIO_CRL		*(volatile uint32_t*)(GPIO_BASE+0x00)
#define GPIO_ODR		*(volatile uint32_t*)(GPIO_BASE+0x0c)
//AFIO register addresses
#define AFIO_BASE		0x40010000
#define AFIO_EXTICR1	*(volatile uint32_t*)(AFIO_BASE+0x0c)
//EXTI register addresses
#define EXTI_BASE 	0x40010400
#define EXTI_IMR	*(volatile uint32_t*)(EXTI_BASE+0x00)
#define EXTI_RTSR	*(volatile uint32_t*)(EXTI_BASE+0x08)
#define EXTI_PR	*(volatile uint32_t*)(EXTI_BASE+0x14)
//NVIC register addresses
#define NVIC_BASE	0xE000E100
#define NVIC_ISER0	*(volatile uint32_t*)(NVIC_BASE+0x00)




void GPIO_init(void);
void EXTI_init(void);

#endif /* GPIO_H_ */

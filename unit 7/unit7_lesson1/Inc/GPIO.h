/*
 * GPIO.h
 *
 *  Created on: Aug 18, 2022
 *      Author: AM
 */

#ifndef GPIOA_H_
#define GPIOA_H_
#include <stdint.h>
#define RCC_BASE		0x40021000
#define RCC_APB2ENR		*(volatile uint32_t*)(RCC_BASE+0x18)
//GPIOA register addresses
#define GPIOA_BASE		0x40010800
#define GPIOA_CRH		*(volatile uint32_t*)(GPIOA_BASE+0x04)
#define GPIOA_CRL		*(volatile uint32_t*)(GPIOA_BASE+0x00)
#define GPIOA_ODR		*(volatile uint32_t*)(GPIOA_BASE+0x0c)
#define GPIOA_IDR		*(volatile uint32_t*)(GPIOA_BASE+0x08)

//GPIOB register addresses
#define GPIOB_BASE		0x40010C00
#define GPIOB_CRH		*(volatile uint32_t*)(GPIOB_BASE+0x04)
#define GPIOB_CRL		*(volatile uint32_t*)(GPIOB_BASE+0x00)
#define GPIOB_ODR		*(volatile uint32_t*)(GPIOB_BASE+0x0c)
#define GPIOB_IDR		*(volatile uint32_t*)(GPIOB_BASE+0x08)




void GPIOA_init(void);


#endif /* GPIOA_H_ */

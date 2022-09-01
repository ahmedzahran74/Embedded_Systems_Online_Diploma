/*
 * STM32f103c6_GPIO.h
 *
 *  Created on: Aug 26, 2022
 *      Author: Ahmed Zahran
 */

#ifndef INC_STM32F103C6_GPIO_H_
#define INC_STM32F103C6_GPIO_H_
#include "stdlib.h"
#include <stdint.h>
#include "STM32f103c6.h"
#include "useful_macros.h"
typedef struct{
	uint8_t GPIO_pin_number;		//specifies the GPIO pins to be configured
									//this parameter can be a value of @ref GPIO_pin_define

	uint8_t GPIO_pin_mode;			//specifies the GPIO pin mode
									//this parameter can be a value of @ref GPIO_pin_mode

	uint8_t GPIO_pin_CNF;				//specifies the GPIO configuration
									//this parameter can be a value of @ref GPIO_pin_CNG


}GPIO_pin_configue_t;

/*--------------------Macros_definitions---------------------*/
// @ref GPIO_pin_define
#define GPIO_PIN_0					0 	//pin 0  selected
#define GPIO_PIN_1					1 	//pin 1  selected
#define GPIO_PIN_2					2 	//pin 2  selected
#define GPIO_PIN_3					3 	//pin 3  selected
#define GPIO_PIN_4					4 	//pin 4  selected
#define GPIO_PIN_5					5 	//pin 5  selected
#define GPIO_PIN_6					6 	//pin 6  selected
#define GPIO_PIN_7					7 	//pin 7  selected
#define GPIO_PIN_8					8 	//pin 8  selected
#define GPIO_PIN_9					9 	//pin 9  selected
#define GPIO_PIN_10					10 	//pin 10 selected
#define GPIO_PIN_11					11 	//pin 11 selected
#define GPIO_PIN_12					12 	//pin 12 selected
#define GPIO_PIN_13					13 	//pin 13 selected
#define GPIO_PIN_14					14 	//pin 14 selected
#define GPIO_PIN_15					15 	//pin 15 selected

// @ref GPIO_pin_mode
#define GPIO_MODE_INPUT				0
#define GPIO_MODE_OUTPUT_10M		1
#define GPIO_MODE_OUTPUT_2M			2
#define GPIO_MODE_OUTPUT_50M		3

// @ref GPIO_pin_CNG
#define GPIO_IN_ANALOG				0
#define GPIO_IN_FLOATING			1
#define GPIO_IN_PULLUP_PULLDOWN		2
#define GPIO_IN_PULLUP				2
#define GPIO_IN_PULLDOWN			3
#define GPIO_OUT_PUSHPULL			0
#define GPIO_OUT_OPENDRAIN			1
#define GPIO_OUT_ALTER_PUSH_PULL	2
#define GPIO_OUT_ALTER_OPENDRAIN	3

// @ref GPIO_LOCK_STATUS
#define GPIO_LOCK_SUCCEDED		1
#define GPIO_LOCK_FAILED		0


void MCAL_GPIO_Init(GPIO_TypeDef*GPIO_portX,GPIO_pin_configue_t*PinConfig);

void MCAL_GPIO_De_Init(GPIO_TypeDef*GPIO_portX);

uint8_t MCAL_GPIO_Read_Pin(GPIO_TypeDef*GPIOx,uint8_t Pinx);

uint16_t MCAL_GPIO_Read_port(GPIO_TypeDef*GPIOx);

void MCAL_GPIO_Write_Pin(GPIO_TypeDef*GPIOx,uint8_t Pinx,uint8_t pin_status);

void MCAL_GPIO_Write_port(GPIO_TypeDef*GPIOx,uint32_t port_status);///////

void MCAL_GPIO_TogglePin (GPIO_TypeDef *GPIO_PortX, uint16_t PinNumber);

uint8_t MCAL_GPIO_Lock_Pin(GPIO_TypeDef *GPIO_PortX, uint16_t PinNumber);


#endif /* INC_STM32F103C6_GPIO_H_ */

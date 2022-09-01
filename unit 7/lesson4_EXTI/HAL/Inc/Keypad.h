/*
 * keypad.h
 *
 * Created: Aug 29, 2022
 *  Author: Ahmed Zahran
 */


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "STM32f103c6.h"
#include "STM32f103c6_GPIO.h"

#define KEYPAD_PORT GPIO_PORTB


#define R0 GPIO_PIN_0
#define R1 GPIO_PIN_1
#define R2 GPIO_PIN_3
#define R3 GPIO_PIN_4
#define C0 GPIO_PIN_5
#define C1 GPIO_PIN_6
#define C2 GPIO_PIN_7
#define C3 GPIO_PIN_8


void Keypad_init();
char Keypad_getkey();

#endif /* KEYPAD_H_ */

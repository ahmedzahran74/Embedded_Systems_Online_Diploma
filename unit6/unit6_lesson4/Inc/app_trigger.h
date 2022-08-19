/*
 * app_trigger.h
 *
 *  Created on: Aug 18, 2022
 *      Author: AM
 */

#ifndef APP_TRIGGER_H_
#define APP_TRIGGER_H_
extern void(*EXTI0_ISR)();
void Assign_GPIO_ISR_Fun(void(*ptr)(void));
void GPIO_ISR_Fun(void);
void App_1(void);


#endif /* APP_TRIGGER_H_ */

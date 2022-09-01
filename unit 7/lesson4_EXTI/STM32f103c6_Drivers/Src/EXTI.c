/*
 * EXTI.c
 *
 *  Created on: Aug 31, 2022
 *      Author: AM
 */


#include"EXTI.h"
#include "STM32f103c6.h"



void(*P_Call_Back_EXTI[16])(void);

#define Get_GPIO_Port(Port)		((Port==GPIO_PORTA)?0:\
		(Port==GPIO_PORTB)?1:\
				(Port==GPIO_PORTC)?2:\
						(Port==GPIO_PORTD)?3:0)


/********************************************
 * @fun   					-MCAL EXTI Init
 * @brief					-Configure EXTIPinx interrupt according to EXTI_Cfg structure passed
 * @parameter[in]			-pointer to Configuration Structure
 * @return value			-none
 * Note						-STM32f103 has A,B,C,D,E ports
 * 							 but LQFP48 only has A,B and part of C,D
 ********************************************/
void EXTI_GPIO_Inite(EXTI_Pin_Cfg_t* EXTI_Cfg)
{
	//configure the pin in input mode
	GPIO_pin_configue_t Pin_cfg;
	Pin_cfg.GPIO_pin_number=EXTI_Cfg->EXTI_pin.Pin_number;
	Pin_cfg.GPIO_pin_mode=GPIO_MODE_INPUT;
	Pin_cfg.GPIO_pin_CNF=GPIO_IN_FLOATING;
	MCAL_GPIO_Init(EXTI_Cfg->EXTI_pin.GPIOx,&Pin_cfg);

	//select the pin by using the AFIO register
	uint8_t Reg;		//it holds the AFIO_EXTICR required register number
	uint8_t Position;	//it holds the register position
	Reg=EXTI_Cfg->EXTI_pin.Pin_number/4;
	Position=(EXTI_Cfg->EXTI_pin.Pin_number%4)*4;
	CLEAR_BITS(AFIO->EXTICR[Reg],Position,4);
	PUT_VALUE_IN_REG(AFIO->EXTICR[Reg],Get_GPIO_Port(EXTI_Cfg->EXTI_pin.GPIOx),Position);
	//----------------Configure EXTI registers----------------

	//configure the edge trigger
	if(EXTI_Cfg->Edge_trigger==RISING_EDGE_TRIGGER)
	{
		SET_BIT(EXTI->RTSR,EXTI_Cfg->EXTI_pin.Pin_number);
	}
	else if(EXTI_Cfg->Edge_trigger==FALLING_EDGE_TRIGGER)
	{
		SET_BIT(EXTI->FTSR,EXTI_Cfg->EXTI_pin.Pin_number);
	}
	else if(EXTI_Cfg->Edge_trigger==RISING_FALLING_EDGE_TRIGGER)
	{
		SET_BIT(EXTI->RTSR,EXTI_Cfg->EXTI_pin.Pin_number);
		SET_BIT(EXTI->FTSR,EXTI_Cfg->EXTI_pin.Pin_number);
	}

	//Enable EXTI mask register
	SET_BIT(EXTI->IMR,EXTI_Cfg->EXTI_pin.Pin_number);

	//Enable NVIC IRQ
	uint8_t NVIC_Set_Reg=(EXTI_Cfg->EXTI_pin.IRQ_Num)/32;			//hold the NVIC set register number
	uint8_t NVIC_Set_Reg_position=(EXTI_Cfg->EXTI_pin.IRQ_Num)%32;	//hold the NVIC set register position
	SET_BIT(NVIC->Set_Enable_Register[NVIC_Set_Reg],NVIC_Set_Reg_position);

	//Assign the function to be called during the interrupt
	P_Call_Back_EXTI[EXTI_Cfg->EXTI_pin.Pin_number]=(EXTI_Cfg->P_IRQ_Callback);
}

/********************************************
 * @fun   					-MCAL EXTI_GPIO_DeInite
 * @brief					-Deinite EXTIPinx interrupt according to EXTI_Cfg structure passed
 * @parameter[in]			-pointer to Configuration Structure
 * @return value			-none
 * Note						-STM32f103 has A,B,C,D,E ports
 * 							 but LQFP48 only has A,B and part of C,D
 ********************************************/

void EXTI_GPIO_DeInite(EXTI_GPIO_Mapping_t* EXTI_Cfg)
{
	//clear rising and falling edge triggering bits
	CLEAR_BITS(EXTI->RTSR,EXTI_Cfg->Pin_number,1);
	CLEAR_BITS(EXTI->FTSR,EXTI_Cfg->Pin_number,1);
	//Disable EXTI mask register
	CLEAR_BITS(EXTI->EMR,EXTI_Cfg->Pin_number,1);
	//Disable NVIC IRQ
	uint8_t NVIC_Set_Reg=(EXTI_Cfg->IRQ_Num)/32;			//holds the NVIC set register number
	uint8_t NVIC_Set_Reg_position=(EXTI_Cfg->IRQ_Num)%32;	//hold the NVIC set register position
	CLEAR_BITS(NVIC->Set_Enable_Register[NVIC_Set_Reg],NVIC_Set_Reg_position,1);
}



/********************************************
 * @fun   					-MCAL EXTI_GPIO_Update
 * @brief					-Update EXTIPinx interrupt Edge triggering and function called according to EXTI_Cfg structure passed
 * @parameter[in]			-pointer to Configuration Structure
 * @return value			-none
 * Note						-STM32f103 has A,B,C,D,E ports
 * 							 but LQFP48 only has A,B and part of C,D
 ********************************************/
void EXTI_GPIO_Update(EXTI_Pin_Cfg_t* EXTI_Cfg)
{
	if(EXTI_Cfg->Edge_trigger==RISING_EDGE_TRIGGER)
	{
		SET_BIT(EXTI->RTSR,EXTI_Cfg->EXTI_pin.Pin_number);
		CLEAR_BITS(EXTI->FTSR,EXTI_Cfg->EXTI_pin.Pin_number,1);
	}
	else if(EXTI_Cfg->Edge_trigger==FALLING_EDGE_TRIGGER)
	{
		SET_BIT(EXTI->FTSR,EXTI_Cfg->EXTI_pin.Pin_number);
		CLEAR_BITS(EXTI->RTSR,EXTI_Cfg->EXTI_pin.Pin_number,1);
	}
	else if(EXTI_Cfg->Edge_trigger==RISING_FALLING_EDGE_TRIGGER)
	{
		SET_BIT(EXTI->RTSR,EXTI_Cfg->EXTI_pin.Pin_number);
		SET_BIT(EXTI->FTSR,EXTI_Cfg->EXTI_pin.Pin_number);
	}

	//Assign the function to be called during the interrupt
	P_Call_Back_EXTI[EXTI_Cfg->EXTI_pin.Pin_number]=EXTI_Cfg->P_IRQ_Callback;
}

void EXTI0_IRQHandler(void)
{
	SET_BIT(EXTI->PR,0);
	P_Call_Back_EXTI[0]();
}
void EXTI1_IRQHandler(void)
{
	SET_BIT(EXTI->PR,1);
	P_Call_Back_EXTI[1]();
}
void EXTI2_IRQHandler(void)
{
	SET_BIT(EXTI->PR,2);
	P_Call_Back_EXTI[2]();
}
void EXTI3_IRQHandler(void)
{
	SET_BIT(EXTI->PR,3);
	P_Call_Back_EXTI[3]();
}
void EXTI4_IRQHandler(void)
{
	SET_BIT(EXTI->PR,4);
	P_Call_Back_EXTI[4]();
}
void EXTI9_5_IRQHandler(void)
{
	if(GET_BIT(EXTI->PR,5)==1)
	{
		SET_BIT(EXTI->PR,5);
		P_Call_Back_EXTI[5]();
	}
	else if (GET_BIT(EXTI->PR,6)==1)
	{
		SET_BIT(EXTI->PR,6);
		P_Call_Back_EXTI[6]();
	}
	else if (GET_BIT(EXTI->PR,7)==1)
	{
		SET_BIT(EXTI->PR,7);
		P_Call_Back_EXTI[7]();
	}
	else if (GET_BIT(EXTI->PR,8)==1)
	{
		SET_BIT(EXTI->PR,8);
		P_Call_Back_EXTI[8]();
	}
	else if (GET_BIT(EXTI->PR,9)==1)
	{
		SET_BIT(EXTI->PR,9);
		P_Call_Back_EXTI[9]();
	}
}

void EXTI15_10_IRQHandler(void)
{
	if(GET_BIT(EXTI->PR,10)==1)
	{
		SET_BIT(EXTI->PR,10);
		P_Call_Back_EXTI[10]();
	}
	else if (GET_BIT(EXTI->PR,11)==1)
	{
		SET_BIT(EXTI->PR,11);
		P_Call_Back_EXTI[11]();
	}
	else if (GET_BIT(EXTI->PR,12)==1)
	{
		SET_BIT(EXTI->PR,12);
		P_Call_Back_EXTI[12]();
	}
	else if (GET_BIT(EXTI->PR,13)==1)
	{
		SET_BIT(EXTI->PR,13);
		P_Call_Back_EXTI[13]();
	}
	else if (GET_BIT(EXTI->PR,14)==1)
	{
		SET_BIT(EXTI->PR,14);
		P_Call_Back_EXTI[14]();
	}

	else if (GET_BIT(EXTI->PR,15)==1)
	{
		SET_BIT(EXTI->PR,15);
		P_Call_Back_EXTI[15]();
	}
}

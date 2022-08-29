/*
 * GPIO.c
 *
 *  Created on: Aug 26, 2022
 *      Author: Ahmed Zahran
 */

#include "STM32f103c6_GPIO.h"

/********************************************
 * @fun   					-MCAL GPIO init
 * @brief					-initialization of GPIO port x according to GPIO_pin_configue_t structure passed
 * @parameter[in]			-pointer to GPIO_portX where X can be (A....E) depending on the device
 * @parameter[in]			-pointer to GPIO_pin_configue_t structure that contain the value to be configured
 * @return value			-none
 * Note						-STM32f103 has A,B,C,D,E ports
 * 							 but LQFP48 only has A,B and part of C,D
 ********************************************/

void MCAL_GPIO_Init(GPIO_TypeDef*GPIO_portX,GPIO_pin_configue_t*PinConfig)
{
	if(PinConfig->GPIO_pin_number<8)//the pins mode in the low register
	{
		//clear the four bits of the pin to be configured
		CLEAR_BITS(GPIO_portX->CRL,PinConfig->GPIO_pin_number*4,4);

		//configure the pin MODE bits
		PUT_VALUE_IN_REG(GPIO_portX->CRL,PinConfig->GPIO_pin_mode,PinConfig->GPIO_pin_number*4);

		//configure the pin CNF bits

		//checking if the pin is input pull up or pull down
		if((PinConfig->GPIO_pin_mode==GPIO_MODE_INPUT) && (PinConfig->GPIO_pin_CNF==GPIO_IN_PULLDOWN||PinConfig->GPIO_pin_CNF==GPIO_IN_PULLUP))
		{

			PUT_VALUE_IN_REG(GPIO_portX->CRL,GPIO_IN_PULLUP_PULLDOWN,((PinConfig->GPIO_pin_number*4)+2));
			if(PinConfig->GPIO_pin_CNF==GPIO_IN_PULLDOWN)
				GPIO_portX->ODR&=~(0x1<<PinConfig->GPIO_pin_number);
			else if(PinConfig->GPIO_pin_CNF==GPIO_IN_PULLUP)
				GPIO_portX->ODR|=(0x1<<PinConfig->GPIO_pin_number);
		}
		else
		{
		PUT_VALUE_IN_REG(GPIO_portX->CRL,PinConfig->GPIO_pin_CNF,((PinConfig->GPIO_pin_number*4)+2));
		}

	}
	if((PinConfig->GPIO_pin_number>=8)&&(PinConfig->GPIO_pin_number<16))//the pins mode in the high register
	{
		//clear the four bits of the pin to be configured
		CLEAR_BITS(GPIO_portX->CRH,(PinConfig->GPIO_pin_number-8)*4,4);

		//configure the pin MODE bits
		PUT_VALUE_IN_REG(GPIO_portX->CRH,PinConfig->GPIO_pin_mode,(PinConfig->GPIO_pin_number-8)*4);

		//checking if the pin is input pull up or pull down
		if((PinConfig->GPIO_pin_mode==GPIO_MODE_INPUT) && (PinConfig->GPIO_pin_CNF==GPIO_IN_PULLDOWN||PinConfig->GPIO_pin_CNF==GPIO_IN_PULLUP))
		{

			PUT_VALUE_IN_REG(GPIO_portX->CRH,GPIO_IN_PULLUP_PULLDOWN,(((PinConfig->GPIO_pin_number-8)*4)+2));
			if(PinConfig->GPIO_pin_CNF==GPIO_IN_PULLDOWN)//if the pin is input with pull down resistance
				GPIO_portX->ODR&=~(0x1<<PinConfig->GPIO_pin_number);
			else if(PinConfig->GPIO_pin_CNF==GPIO_IN_PULLUP)//if the pin is input with pullup resistance
				GPIO_portX->ODR|=(0x1<<PinConfig->GPIO_pin_number);
		}
		else
		{
		PUT_VALUE_IN_REG(GPIO_portX->CRH,PinConfig->GPIO_pin_CNF,(((PinConfig->GPIO_pin_number-8)*4)+2));
		}
	}

}
	/********************************************
	 * @fun   					-MCAL GPIO Deinit
	 * @brief					-reset all GPIOx register
	 * @parameter[in]			-pointer to GPIO_portX where X can be (A....E) depending on the device
	 * @return value			-none
	 * Note						-STM32f103 has A,B,C,D,E ports
	 * 							 but LQFP48 only has A,B and part of C,D
	 ********************************************/
	void GPIO_De_Init(GPIO_TypeDef*GPIO_portX)
	{
		if(GPIO_portX==GPIO_PORTA)
		{
			RCC->APB2RSTR|=1<<2;
			RCC->APB2RSTR&=~(1<<2);

		}
		else if(GPIO_portX==GPIO_PORTB)
		{
			RCC->APB2RSTR|=1<<3;
			RCC->APB2RSTR&=~(1<<3);
		}
		else if(GPIO_portX==GPIO_PORTC)
		{
			RCC->APB2RSTR|=1<<4;
			RCC->APB2RSTR&=~(1<<4);
		}
		else if(GPIO_portX==GPIO_PORTD)
		{
			RCC->APB2RSTR|=1<<5;
			RCC->APB2RSTR&=~(1<<5);
		}
		else if(GPIO_portX==GPIO_PORTE)
		{
			RCC->APB2RSTR|=1<<6;
			RCC->APB2RSTR&=~(1<<6);
		}

	}

	/********************************************
	 * @fun   					-MCAL GPIO Read Pin
	 * @brief					-Read pinx from GPIOx port
	 * @parameter[in]			-pointer to GPIO_portX where X can be (A....E) depending on the device
	 * @parameter[in]			-pin number
	 * @return value			-none
	 * Note						-STM32f103 has A,B,C,D,E ports
	 * 							 but LQFP48 only has A,B and part of C,D
	 ********************************************/
	uint8_t MCAL_GPIO_Read_Pin(GPIO_TypeDef*GPIOx,uint8_t Pinx)
	{
		uint8_t pin_status=0;
		pin_status=0x1&(GPIOx->IDR>>Pinx);
		return pin_status;
	}

	/********************************************
	 * @fun   					-MCAL GPIO Read port
	 * @brief					-Read portx from GPIOx port
	 * @parameter[in]			-pointer to GPIO_portX where X can be (A....E) depending on the device
	 * @return value			-the port status
	 * Note						-STM32f103 has A,B,C,D,E ports
	 * 							 but LQFP48 only has A,B and part of C,D
	 ********************************************/
	uint16_t MCAL_GPIO_Read_port(GPIO_TypeDef*GPIOx)
	{
		uint32_t port_status;
		port_status=(uint16_t)(GPIOx->IDR);
		return port_status;
	}


	/********************************************
	 * @fun   					-MCAL GPIO write Pin
	 * @brief					-write to pinx from GPIOx port
	 * @parameter[in]			-GPIOx: pointer to GPIO_portX where X can be (A....E) depending on the device
	 * @parameter[in]			-Pinx: pin number
	 * @parameter[in]			-Value: pin value
	 * @return value			-none
	 * Note						-STM32f103 has A,B,C,D,E ports
	 * 							 but LQFP48 only has A,B and part of C,D
	 ********************************************/

	void MCAL_GPIO_Write_Pin(GPIO_TypeDef*GPIOx,uint8_t Pinx,uint8_t pin_status)
	{
		CLEAR_BITS(GPIOx->ODR,Pinx,1);
		GPIOx->ODR|=pin_status<<Pinx;
	}

	/********************************************
	 * @fun   					-MCAL GPIO write port
	 * @brief					-write value to portx
	 * @parameter[in]			-GPIOx: pointer to GPIO_portX where X can be (A....E) depending on the device
	 * @parameter[in]			-Value: port value
	 * @return value			-none
	 * Note						-STM32f103 has A,B,C,D,E ports
	 * 							 but LQFP48 only has A,B and part of C,D
	 ********************************************/
	void MCAL_GPIO_Write_port(GPIO_TypeDef*GPIOx,uint32_t port_status)
	{
		CLEAR_BITS(GPIOx->ODR,0,16);
		GPIOx->ODR=port_status;
	}


	/********************************************
	 * @fun   					-MCAL GPIO write Pin
	 * @brief					-toggle to pinx from GPIOx port
	 * @parameter[in]			-GPIOx: pointer to GPIO_portX where X can be (A....E) depending on the device
	 * @parameter[in]			-Pinx: pin number
	 * @return value			-none
	 * Note						-STM32f103 has A,B,C,D,E ports
	 * 							 but LQFP48 only has A,B and part of C,D
	 ********************************************/
	void MCAL_GPIO_TogglePin (GPIO_TypeDef *GPIO_PortX, uint16_t PinNumber)
	{
		TOGGLE_BIT(GPIO_PortX->ODR,PinNumber);
	}

	/********************************************
	 * @fun   					-MCAL GPIO Lock Pin
	 * @brief					-Lock pinx from GPIOx port configuration
	 * @parameter[in]			-GPIOx: pointer to GPIO_portX where X can be (A....E) depending on the device
	 * @parameter[in]			-Pinx: pin number
	 * @return value			-return the pin lock status this can be a value of @ref GPIO_LOCK_STATUS in GPIO.h
	 * Note						-STM32f103 has A,B,C,D,E ports
	 * 							 but LQFP48 only has A,B and part of C,D
	 ********************************************/

	uint8_t MCAL_GPIO_Lock_Pin(GPIO_TypeDef *GPIO_PortX, uint16_t PinNumber)
	{
		/*
		 *  Bit 16 LCKK[16]: Lock key
			This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
			0: Port configuration lock key not active
			1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
			LOCK key writing sequence:
			Write 1
			Write 0
			Write 1
			Read 0
			Read 1 (this read is optional but confirms that the lock is active)
			Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
			Any error in the lock sequence will abort the lock.
			Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
			These bits are read write but can only be written when the LCKK bit is 0.
			0: Port configuration not locked
			1: Port configuration locked.
		 */

		uint16_t temp;
		SET_BIT(GPIO_PortX->LCKR,PinNumber);

		//Write 1

		SET_BIT(GPIO_PortX->LCKR,16);

		//Write 0

		CLEAR_BITS(GPIO_PortX->LCKR,16,1);

		//Write 1

		SET_BIT(GPIO_PortX->LCKR,16);

		//Read 0

		temp=GET_BIT(GPIO_PortX->LCKR,16);

		//Read 1

		if(GET_BIT(GPIO_PortX->LCKR,16)==1)
			return GPIO_LOCK_SUCCEDED;
		else
			return GPIO_LOCK_FAILED;


	}


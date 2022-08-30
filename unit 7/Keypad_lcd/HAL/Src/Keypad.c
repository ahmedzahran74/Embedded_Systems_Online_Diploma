/*
 * Keypad.c
 *
 *  Created on: Aug 29, 2022
 *      Author: AM
 */

#include"keypad.h"

static GPIO_pin_configue_t PinCfg;

int KEYPAD_R[]={R0,R1,R2,R3};
int KEYPAD_C[]={C0,C1,C2,C3};

void Keypad_init()
{
	PinCfg.GPIO_pin_number = R0;
	PinCfg.GPIO_pin_mode = GPIO_MODE_INPUT ;
	PinCfg.GPIO_pin_CNF = GPIO_IN_PULLDOWN ;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_pin_number = R1;
	PinCfg.GPIO_pin_mode = GPIO_MODE_INPUT ;
	PinCfg.GPIO_pin_CNF = GPIO_IN_PULLDOWN ;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);


	PinCfg.GPIO_pin_number = R2;
	PinCfg.GPIO_pin_mode = GPIO_MODE_INPUT ;
	PinCfg.GPIO_pin_CNF = GPIO_IN_PULLDOWN ;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_pin_number = R3;
	PinCfg.GPIO_pin_mode = GPIO_MODE_INPUT ;
	PinCfg.GPIO_pin_CNF = GPIO_IN_PULLDOWN ;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);


	PinCfg.GPIO_pin_number = C0;
	PinCfg.GPIO_pin_mode = GPIO_MODE_OUTPUT_10M ;
	PinCfg.GPIO_pin_CNF = GPIO_OUT_PUSHPULL ;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_pin_number = C1;
	PinCfg.GPIO_pin_mode = GPIO_MODE_OUTPUT_10M ;
	PinCfg.GPIO_pin_CNF = GPIO_OUT_PUSHPULL ;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_pin_number = C2;
	PinCfg.GPIO_pin_mode = GPIO_MODE_OUTPUT_10M ;
	PinCfg.GPIO_pin_CNF = GPIO_OUT_PUSHPULL ;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_pin_number = C3;
	PinCfg.GPIO_pin_mode = GPIO_MODE_OUTPUT_10M ;
	PinCfg.GPIO_pin_CNF = GPIO_OUT_PUSHPULL ;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);
}

char Keypad_getkey()
{
	volatile int i, j;
	for (i=0;i<4;i++)
	{

		MCAL_GPIO_Write_Pin(KEYPAD_PORT, KEYPAD_C[0], LOW);
		MCAL_GPIO_Write_Pin(KEYPAD_PORT, KEYPAD_C[1], LOW);
		MCAL_GPIO_Write_Pin(KEYPAD_PORT, KEYPAD_C[2], LOW);
		MCAL_GPIO_Write_Pin(KEYPAD_PORT, KEYPAD_C[3], LOW);
		MCAL_GPIO_Write_Pin(KEYPAD_PORT, KEYPAD_C[i],HIGH);

		for(j=0;j<4;j++)
		{

			if((MCAL_GPIO_Read_Pin(KEYPAD_PORT, KEYPAD_R[j]))==1)
			{
				while((MCAL_GPIO_Read_Pin(KEYPAD_PORT, KEYPAD_R[j]))==1);
				switch(i)
				{
				case 0:
				{
					if(j==0) return '7';
					else if (j==1) return '4';
					else if (j==2) return '1';
					else if (j==3) return '!';
				}break;
				case 1:
				{
					if(j==0) return '8';
					else if (j==1) return '5';
					else if (j==2) return '2';
					else if (j==3) return '0';
				}break;
				case 2:
				{
					if(j==0) return '9';
					else if (j==1) return '6';
					else if (j==2) return '3';
					else if (j==3) return '=';
				}break;
				case 3:
				{
					if(j==0) return '/';
					else if (j==1) return '*';
					else if (j==2) return '-';
					else if (j==3) return '+';
				}break;
				}
			}
		}

	}
	return 'N';
}

/*
 * main.c
 *
 *  Created on: Aug 1, 2022
 *      Author: AM
 */
#include <stdint.h>
#include "stack.h"
#include <stdio.h>
ELEMENT_TYPE buffer[BUFFER_LENGTH];
ELEMENT_TYPE buffer_2[BUFFER_LENGTH_2];

void main()
{
	LIFO_Buf_t lifo;
	LIFO_Buf_t lifo_2;

	LIFO_init(&lifo,buffer,BUFFER_LENGTH);
	LIFO_init(&lifo_2,buffer_2,BUFFER_LENGTH_2);

	ELEMENT_TYPE item;
	for (int i=0;i<BUFFER_LENGTH;i++)
	{
		LIFO_Add_item(&lifo,(ELEMENT_TYPE)i);
		printf("the item %d is added \n",i);

	}
	for (int i=BUFFER_LENGTH_2;i>0;i--)
	{
		LIFO_Add_item(&lifo_2,(ELEMENT_TYPE)i);
		printf("the item %d is added \n",i);

	}
	for (int i=0;i<BUFFER_LENGTH;i++)
	{
		LIFO_Get_item(&lifo,&item);
		printf("the item %d is popped\n",item);
	}
	for (int i=0;i<BUFFER_LENGTH_2;i++)
	{
		LIFO_Get_item(&lifo_2,&item);
		printf("the item %d is popped\n",item);
	}

}

/*
 * main.c
 *
 *  Created on: Aug 1, 2022
 *      Author: AM
 */
#include <stdint.h>
#include "stack.h"
#include <stdio.h>
#define BUFFER_LENGTH 10
ELEMENT_TYPE buffer[BUFFER_LENGTH];
void main()
{
	LIFO_Buf_t lifo;
	LIFO_init(&lifo,buffer,BUFFER_LENGTH);
	ELEMENT_TYPE item;
	for (int i=0;i<BUFFER_LENGTH;i++)
	{
		LIFO_Add_item(&lifo,(ELEMENT_TYPE)i);
		printf("the item is: %d\n",i);

	}
	for (int i=0;i<BUFFER_LENGTH;i++)
	{
		LIFO_Get_item(&lifo,&item);
		printf("the item is: %d\n",item);
	}

}

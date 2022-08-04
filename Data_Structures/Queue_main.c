/*
 * Queue_main.c
 *
 *  Created on: Aug 2, 2022
 *      Author: AM
 */
#include "Queue.h"
#include<stdint.h>
#include <stdio.h>
ELEMENT_TYPE buff[width1];
ELEMENT_TYPE buff2[width2];

void main ()
{
	ELEMENT_TYPE item;
	FIFO_Buf_t FIFO;
	FIFO_Buf_t FIFO2;

	if (FIFO_Init(&FIFO,buff,width1)==FIFO_No_Error)
	{
		for(int i=0;i<7;i++)
		{
		FIFO_Enqueue(&FIFO,(ELEMENT_TYPE)i);
		}
	}
	FIFO_Print(&FIFO);
	FIFO_Dequeue(&FIFO,&item);
	FIFO_Dequeue(&FIFO,&item);
	FIFO_Print(&FIFO);
	FIFO_Enqueue(&FIFO,20);
	FIFO_Print(&FIFO);
	if (FIFO_Init(&FIFO2,buff2,width2)==FIFO_No_Error)
	{
		for(int i=9;i>0;i--)
		{
		FIFO_Enqueue(&FIFO2,(ELEMENT_TYPE)i);
		}
	}
	FIFO_Print(&FIFO2);
	FIFO_Dequeue(&FIFO2,&item);
	FIFO_Dequeue(&FIFO2,&item);
	FIFO_Print(&FIFO2);
	FIFO_Enqueue(&FIFO2,20);
	FIFO_Print(&FIFO2);

}

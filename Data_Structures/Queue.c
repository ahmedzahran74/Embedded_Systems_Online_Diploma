/*
 * Queue.c
 *
 *  Created on: Aug 1, 2022
 *      Author: AM
 */
#include "Queue.h"
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
FIFO_Buf_Status FIFO_Init(FIFO_Buf_t* FIFO,ELEMENT_TYPE *buffer,uint32_t length)
{
	if(buffer==NULL)
		return FIFO_Null;
	FIFO->base=buffer;
	FIFO->head=buffer;
	FIFO->tail=buffer;
	FIFO->length=length;
	FIFO->count=0;
	return FIFO_No_Error;

}
FIFO_Buf_Status FIFO_Enqueue(FIFO_Buf_t* FIFO,ELEMENT_TYPE item)
{
	//uint8_t flag=0;//to check if the head less than the tail
	//check if the queue is empty
	//if(FIFO->length-(((uint32_t)FIFO->head)+1)+((uint32_t)FIFO->tail)-flag * FIFO->length==0)
	if(FIFO_Is_Full(FIFO)==FIFO_No_Error)
	{
		*(FIFO->head)=item;
		if(FIFO->head==FIFO->base+FIFO->length-1)
			FIFO->head=FIFO->base;
		else
			FIFO->head++;
		FIFO->count++;
		printf("FIFO_Enqueue (%d) done\n",item);
		return FIFO_No_Error;
	}
	else
	{
		printf("FIFO_Enqueue (%d) failed\n",item);
		return FIFO_Full;
	}
}
FIFO_Buf_Status FIFO_Dequeue(FIFO_Buf_t* FIFO,ELEMENT_TYPE *item)
{
	if(FIFO_Is_Empty(FIFO)==FIFO_Empty)
	{
		printf("FIFO_denqueue (%d) failed\n",*FIFO->tail);
		return FIFO_Empty;
	}
	else
	{
		*item=*(FIFO->tail);
		if(FIFO->tail==FIFO->base+FIFO->length-1)
			FIFO->tail=FIFO->base;
		else
			FIFO->tail++;
		FIFO->count--;
		printf("FIFO_denqueue (%d) done\n",*item);
		return FIFO_No_Error;
	}
}
FIFO_Buf_Status FIFO_Is_Full(FIFO_Buf_t* FIFO)
{
	if (FIFO->count==FIFO->length)
		return FIFO_Full;
	else
		return FIFO_No_Error;


}
FIFO_Buf_Status FIFO_Is_Empty(FIFO_Buf_t* FIFO)
{
	//if(FIFO->tail==FIFO->head)
	if (FIFO->count==0)
		return FIFO_Empty;
	else
		return FIFO_No_Error;
}
void FIFO_Print(FIFO_Buf_t* FIFO)
{
	for (int i=0;i<FIFO->count;i++)
	{
		if((FIFO->tail+i)<(FIFO->base+FIFO->length))
			printf("the next element is: %d\n",*(FIFO->tail+i));
		else
			printf("the next element is: %d\n",*(FIFO->tail+i-FIFO->length));

	}
}

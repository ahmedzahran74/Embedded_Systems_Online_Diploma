/*
 * Queue.h


 *
 *  Created on: Aug 1, 2022
 *      Author: AM
 */
/*to make a queue first define array of any type
 * just define the type of array using ELEMENT_TYPE macro
 * then define array size using width macros
 * then define a structure to hold the queue parameters
 * you can make more than one queue
 */
#ifndef QUEUE_H_
#define QUEUE_H_
#include <stdint.h>
#define width1 5
#define width2 8
#define ELEMENT_TYPE uint32_t

typedef struct {
	uint32_t length;
	uint32_t count;
	ELEMENT_TYPE*base;
	ELEMENT_TYPE*tail;
	ELEMENT_TYPE*head;
}FIFO_Buf_t;
typedef enum{
	FIFO_No_Error,
	FIFO_Null,
	FIFO_Empty,
	FIFO_Full,

}FIFO_Buf_Status;
//FIFO_APIs
FIFO_Buf_Status FIFO_Init(FIFO_Buf_t* FIFO,ELEMENT_TYPE *buffer,uint32_t length);
FIFO_Buf_Status FIFO_Enqueue(FIFO_Buf_t* FIFO,ELEMENT_TYPE item);
FIFO_Buf_Status FIFO_Dequeue(FIFO_Buf_t* FIFO,ELEMENT_TYPE *item);
FIFO_Buf_Status FIFO_Is_Full(FIFO_Buf_t* FIFO);
FIFO_Buf_Status FIFO_Is_Empty(FIFO_Buf_t* FIFO);
void FIFO_Print(FIFO_Buf_t* FIFO);


#endif /* QUEUE_H_ */

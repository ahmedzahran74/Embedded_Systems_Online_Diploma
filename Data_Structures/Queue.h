/*
 * Queue.h

 *
 *  Created on: Aug 1, 2022
 *      Author: AM
 */
#ifndef QUEUE_H_
#define QUEUE_H_
#include <stdint.h>
#define width1 5
#define ELEMENT_TYPE uint32_t
ELEMENT_TYPE buff[width1];

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

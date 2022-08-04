/*
 * stack.h

 *
 *  Created on: Aug 1, 2022
 *      Author: AM
 */
/*to make a stack first define array of any type
 * just define the type of array using ELEMENT_TYPE macro
 * then define array size using BUFFER_LENGTH macros
 * then define a structure to hold the stack parameters
 * you can make more than one queue
 */
#ifndef STACK_H_
#define STACK_H_
#include <stdint.h>
#define ELEMENT_TYPE uint8_t
#define BUFFER_LENGTH 10
#define BUFFER_LENGTH_2 6


typedef struct{
	uint32_t length;
	uint32_t count;
	ELEMENT_TYPE*head;
	ELEMENT_TYPE*base;
}LIFO_Buf_t;
typedef enum{
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_Null
}LIFO_status;
LIFO_status LIFO_Add_item(LIFO_Buf_t *lifo_buf,ELEMENT_TYPE item);
LIFO_status LIFO_Get_item(LIFO_Buf_t *lifo_buf,ELEMENT_TYPE *item);
LIFO_status LIFO_init(LIFO_Buf_t*lifo_buf,ELEMENT_TYPE*buf,uint32_t length);

#endif /* STACK_H_ */

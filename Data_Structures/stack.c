/*
 * stack.c
 *
 *  Created on: Aug 1, 2022
 *      Author: AM
 */


#include <stdint.h>
#include <stddef.h>
#include "stack.h"
LIFO_status LIFO_init(LIFO_Buf_t*lifo_buf,ELEMENT_TYPE*buf,uint32_t length)
{
	//check if the buffer exist
	if(buf==NULL)
		return LIFO_Null;
	lifo_buf->base=buf;
	lifo_buf->head=buf;
	lifo_buf->length=length;
	lifo_buf->count=0;
	return LIFO_no_error;
}

LIFO_status LIFO_Add_item(LIFO_Buf_t *lifo_buf,ELEMENT_TYPE item)
{
	//check if the LIFO is full
	if(lifo_buf->count==lifo_buf->length)
		return LIFO_full;
	//adding the item
	*(lifo_buf->head)=item;
	lifo_buf->count++;
	lifo_buf->head++;
	return LIFO_no_error;
}
LIFO_status LIFO_Get_item(LIFO_Buf_t *lifo_buf,ELEMENT_TYPE *item)
{
	//check if the lifo is empty
	if(lifo_buf->head==lifo_buf->base)
		return LIFO_empty;
	lifo_buf->head--;
	*item=*(lifo_buf->head);
	lifo_buf->count--;
	return LIFO_no_error;
}

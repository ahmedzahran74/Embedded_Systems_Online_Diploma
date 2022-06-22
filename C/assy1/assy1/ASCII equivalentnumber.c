/*
 * ASCII equivalentnumber.c
 *
 *  Created on: Jun 22, 2022
 *      Author: Ahmed Zahran
 */


#include "stdio.h"
void main (int argc,char **argv)
{
	char x;
	printf("enter a character: \n");
	fflush(stdin);fflush(stdout);
	scanf("%c",&x);
	printf("ASCII value of %c = %d",x,x);
}

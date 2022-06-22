/*
 * product of 2 numbers.c
 *
 *  Created on: Jun 22, 2022
 *      Author: Ahmed Zahran
 */


#include "stdio.h"
void main (int argc,char **argv)
{
	float x,y;
	printf("enter two numbers: \n");
	fflush(stdin);fflush(stdout);
	scanf("%f%f",&x,&y);
	printf("the product is: %10.2f",x*y);
}

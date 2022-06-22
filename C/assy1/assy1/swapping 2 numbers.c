/*
 * swapping 2 numbers.c
 *
 *  Created on: Jun 22, 2022
 *      Author: Ahmed Zahran
 */
#include "stdio.h"
void main (int argc,char **argv)
{
	float a,b,temp;
	printf("Enter value of a: \n");
	fflush(stdin);fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b: \n");
	fflush(stdin);fflush(stdout);
	scanf("%f",&b);
	temp=a;
	a=b;
	b=temp;
	printf("After swapping, value of a = %.2f\n",a);
	fflush(stdin);fflush(stdout);
	printf("After swapping, value of b = %.2f\n",b);
	fflush(stdin);fflush(stdout);

}


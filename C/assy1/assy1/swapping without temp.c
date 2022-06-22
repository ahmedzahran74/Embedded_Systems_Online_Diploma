/*
 * swapping without temp.c
 *
 *  Created on: Jun 22, 2022
 *      Author: Ahmed Zahran
 */


#include "stdio.h"
void main (int argc,char **argv)
{
	int a,b;
	printf("Enter value of a: \n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&a);
	printf("Enter value of b: \n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&b);
	a=a^b;
	b=a^b;
	a=a^b;
	printf("After swapping, value of a = %d\n",a);
	fflush(stdin);fflush(stdout);
	printf("After swapping, value of b = %d\n",b);
	fflush(stdin);fflush(stdout);

}

/*
 * calculate the factorial of a number.c
 *
 *  Created on: Jun 22, 2022
 *      Author: Ahmed Zahran
 */


#include "stdio.h"
void main (int argc,char **argv)
{
	int x,product;
	char s;
	do
	{
	product=1;
	printf("enter a positive number : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
	if(x>0)
	{
	for(int i=1;i<=x;i++)
	{
		product*=i;
	}
	printf("factorial = %d\n",product);
	fflush(stdin);fflush(stdout);
	}
	else
	{
		printf("wrong the number should be positive\n");
		fflush(stdin);fflush(stdout);
	}
	printf("enter 1 to continue or other to break\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&s);
	}while(s==1);
}

/*
 * calculator.c
 *
 *  Created on: Jun 22, 2022
 *      Author: Ahmed Zahran
 */


#include "stdio.h"
void main (int argc,char **argv)
{
	int x,y,result;
	char operation;
	printf("enter 2 numbers\n");
	fflush(stdin);fflush(stdout);
	scanf("%d%d",&x,&y);
	printf("enter + or - ot * or /");
	fflush(stdin);fflush(stdout);
	scanf("%c",&operation);
	if(operation=='+')
	{
		result=x+y;
		printf("%d\n",result);
	fflush(stdin);fflush(stdout);
	}
	else if (operation=='-')
	{
		result=x-y;
		printf("%d\n",result);
		fflush(stdin);fflush(stdout);
	}
	else if(operation=='*')
	{
		result=x*y;
		printf("%d\n",result);
		fflush(stdin);fflush(stdout);
	}
	else if (operation=='/')
	{
		result=x/y;
		printf("%d\n",result);
		fflush(stdin);fflush(stdout);
	}
	else
		printf("wrong operation");



}

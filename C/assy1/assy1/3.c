/*
 * 3.c
 *
 *  Created on: Jun 22, 2022
 *      Author: Ahmed Zahran
 */


#include "stdio.h"
void main (int argc,char **argv)
{
	int x,y;
	printf("enter two numbers: \n");
	fflush(stdin);fflush(stdout);
	scanf("%d%d",&x,&y);
	printf("the sumation is: %d",x+y);
}

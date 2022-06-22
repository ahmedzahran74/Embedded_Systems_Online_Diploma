/*
 * sum from 1 to n .c
 *
 *  Created on: Jun 22, 2022
 *      Author: Ahmed Zahran
 */


#include "stdio.h"
void main (int argc,char **argv)
{
	int x,sum=0;
	printf("enter an integer: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
	for(int i=1;i<=x;i++)
	{
		sum+=i;
	}
	printf("sum = %d",sum);
	fflush(stdin);fflush(stdout);
}

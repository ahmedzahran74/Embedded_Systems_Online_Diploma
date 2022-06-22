/*
 * check even or odd.c
 *
 *  Created on: Jun 22, 2022
 *      Author: Ahmed Zahran
 */


#include "stdio.h"
void main (int argc,char **argv)
{
	int x,i;
	do
	{
		printf("enter the number you want to check: \n");
		fflush(stdin);fflush(stdout);
		scanf("%d",&x);
		if (x%2==0)
		{
			printf("%d is even\n",x);
			fflush(stdin);fflush(stdout);
		}
		else
		{
			printf("%d is odd\n",x);
			fflush(stdin);fflush(stdout);
		}
		printf("enter 1 to continue other to break\n");
		fflush(stdin);fflush(stdout);
		scanf("%d",&i);
	}	while(i==1);

}

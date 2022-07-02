/*
 * armstrong number.c
 *
 *  Created on: Jul 2, 2022
 *      Author: AM
 */


#include"stdio.h"
int power (int x, int y)
{
	int result=1;
	for (int i=0;i<y;i++)
		result*=x;
	return result;
}
int main()
{
	int number,q,result=0,rem,digits=0;
	printf("enter a number you want to check: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&number);
	q=number;
	while(q!=0)
	{
		digits++;
		q/=10;
	}
	q=number;
	for (int i=0;i<digits;i++)
	{
		rem=q%10;
		q/=10;
		result+=power(rem,digits);
	}
	if (result == number)
	{
		printf("the number is armstrong\n");
		fflush(stdin);fflush(stdout);
	}
	else
	{
		printf("the number is not armstrong\n");
		fflush(stdin);fflush(stdout);
	}
}

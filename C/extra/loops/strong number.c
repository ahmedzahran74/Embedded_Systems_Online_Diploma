/*
 * strong number.c
 *
 *  Created on: Jul 2, 2022
 *      Author: AM
 */
int factorial(int n)
{
	int result=1;
	for (int i=1;i<=n;i++)
		result*=i;
	return result;
}
#include"stdio.h"

int main()
{
	int number,q,result=0,rem;
	printf("enter a number you want to check: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&number);
	q=number;
	while(q!=0)
	{
		rem=q%10;
		q/=10;
		result+=factorial(rem);
	}
	if(result==number)
	{
		printf("the number is strong");
		fflush(stdin);fflush(stdout);
	}
	else
	{
		printf("the number is not strong");
		fflush(stdin);fflush(stdout);
	}
}

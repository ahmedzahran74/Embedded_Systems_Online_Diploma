/*
 * test.c
 *
 *  Created on: Jul 2, 2022
 *      Author: AM
 */


#include"stdio.h"
int main()
{
	int number,q,rem,result=0;
	printf("enter a number you want to check: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&number);
	q=number;
	while(q!=0)
	{
		rem=q%10;
		result=result*10+rem;
		q/=10;
	}
	if(result==number)
	{
		printf("the numer is plaindrome.\n");
		fflush(stdin);fflush(stdout);
	}
	else
	{
		printf("the number is not a plaindrome.\n");
		fflush(stdin);fflush(stdout);
	}
}

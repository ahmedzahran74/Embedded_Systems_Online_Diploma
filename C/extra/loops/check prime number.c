/*
 * check prime number.c
 *
 *  Created on: Jul 2, 2022
 *      Author: AM
 */


#include"stdio.h"
#include "stdbool.h"
bool check_if_anumber_is_prime(int num)
{
	bool result=0;
	for (int i=2;i<num;i++)
	{
		if(num%i==0)
			break;
		if(num-i==1)
			result=true;
	}
	return result;
}
int main()
{
	bool result;
	int number;
	printf("enter a number: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&number);
	result=check_if_anumber_is_prime(number);
	if (result==true)
	{
		printf("the number is prime ");
		fflush(stdin);fflush(stdout);
	}
	else
	{
		printf("the number is not prime ");
		fflush(stdin);fflush(stdout);
	}

}

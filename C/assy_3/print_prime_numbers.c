/*
 * print_prime_numbers.c
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
	int num_1,num_2,lower,upper;
	bool result;
	printf("enter 2 numbers: ");
	fflush(stdin);fflush(stdout);
	scanf("%d %d",&num_1,&num_2);
	lower=(num_1<num_2) ? num_1:num_2;
	upper=(num_1>num_2) ? num_1:num_2;
	printf("prime numbers between %d and %d are: ",num_1,num_2);
	fflush(stdin);fflush(stdout);
	for(int i=lower;i<=upper;i++)
	{
		result=check_if_anumber_is_prime(i);
		if(result==true)
		{
			printf("%d\t",i);
			fflush(stdin);fflush(stdout);
		}
	}

}

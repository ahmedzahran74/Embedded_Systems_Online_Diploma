/*
 * adding 2 numbers without + operator.c
 *
 *  Created on: Jul 2, 2022
 *      Author: AM
 */


#include"stdio.h"
int add_without_plus(int x,int y)
{
	int result,and,save;//save is used to save and variable before and operation
	result=x^y;
	and=x&y;
	while(and!=0)
	{
		and=and<<1;
		save=and;
		and&=result;
		result^=save;

	}
	return result;

}
int main()
{
	int x,y;
	printf("enter 2 numbers first number");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
	scanf("%d",&y);
	printf("the result is %d",add_without_plus(x,y));
	fflush(stdin);fflush(stdout);

}

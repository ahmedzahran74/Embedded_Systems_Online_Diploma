/*
 * factorial using recursion.c
 *
 *  Created on: Jul 2, 2022
 *      Author: AM
 */


#include"stdio.h"
int factorial (int n)
{
	if(n==1)
		return 1;
	else
		return n*factorial(n-1);
}
int main()
{
	int num;
	printf("enter a number: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);
	printf("the factorial of %d is %d",num,factorial(num));
	fflush(stdin);fflush(stdout);


}

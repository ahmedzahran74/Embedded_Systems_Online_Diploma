/*
 * power of a number using recursion.c
 *
 *  Created on: Jul 2, 2022
 *      Author: AM
 */


#include"stdio.h"
int power_using_recursion(int x,int y)
{
	if (y==1)
		return x;
	else
		return x*power_using_recursion(x,y-1);
}
int main()
{
	int x,y;
	printf("enter base number: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
	printf("enter power number: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&y);
	printf("%d power %d is equal %d",x,y,power_using_recursion(x,y));
}

/*
 * fibonacci series.c
 *
 *  Created on: Jul 2, 2022
 *      Author: AM
 */
#include"stdio.h"
void print_fabonacci_series(int num)
{
	int a=0,b=1;
	for(int i=0;i<num;i++)
	{
		printf("%d\t",a);
		b=b+a;
		a=b-a;

	}
}
int main()
{
	print_fabonacci_series(1);
}


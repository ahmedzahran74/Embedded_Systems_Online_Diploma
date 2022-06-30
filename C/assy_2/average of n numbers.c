/*
 * average of n numbers.c
 *
 *  Created on: Jun 30, 2022
 *      Author: AM
 */

#include"stdio.h"
int main()
{
	float arr[100];
	int number;
	float sum=0,avg;
	char s[]={"enter the number of elements\n"};
	printf(s);
	fflush(stdin);fflush(stdout);

	scanf("%d",&number);
	for(int i=0;i<number;i++)
	{
		printf("enter a number: ");
		fflush(stdin);fflush(stdout);
		scanf("%f",&arr[i]);
		sum+=arr[i];
	}
	avg=sum/number;
	printf("the average is = %f",avg);
	fflush(stdin);fflush(stdout);

}


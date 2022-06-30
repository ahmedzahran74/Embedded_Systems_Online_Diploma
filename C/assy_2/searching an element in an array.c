/*
 * searching an element in an array.c
 *
 *  Created on: Jun 30, 2022
 *      Author: AM
 */


/*
 * inserting an element in an array.c
 *
 *  Created on: Jun 30, 2022
 *      Author: AM
 */

#include "stdio.h"
void main (int argc,char **argv)
{
	int array[100];
	int n,number,index=0;
	printf("enter the number of array elements: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	printf("enter the array elements\n");
	fflush(stdin);fflush(stdout);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	printf("enter the number you want to check: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&number);
	for(int i=0;i<n;i++)
	{
		if(number==array[i])
		{
			index=i+1;
			break;
		}
	}
	if(index!=0)
	{
		printf("%d exist in at the location %d",number,index);
		fflush(stdin);fflush(stdout);
	}
	else
	{
		printf("not exist");
		fflush(stdin);fflush(stdout);
	}
}

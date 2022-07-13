/*
 * assy5_4.c
 *
 *  Created on: Jul 13, 2022
 *      Author: AM
 */

#include"stdio.h"
#define ARR_ELEMENTS 5
int main()
{
	int arr[ARR_ELEMENTS];
	int*ptr;
	int i=1;
	for (ptr=arr;ptr<arr+ARR_ELEMENTS;ptr++,i++)
	{
		printf("Enter element %d\n",i);
		fflush(stdin);fflush(stdout);
		scanf("%d",ptr);
	}
	printf("The elements in reverse order are :\n");
	for(ptr--;ptr>=arr;ptr--)
	{
		printf("%d\n",*ptr);
		fflush(stdin);fflush(stdout);
	}

}

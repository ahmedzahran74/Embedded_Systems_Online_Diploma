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
	int arr[100];
	int elements,insert;
	int location;
	printf("enter the number of elements :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&elements);
	printf("enter the elements\n");
	fflush(stdin);fflush(stdout);
	for (int i=0;i<elements;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("enter the number you want to insert: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&insert);
	printf("enter the location: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&location);
	for (int i=elements;i>=location;i--)
	{
		arr[i]=arr[i-1];
	}
	arr[location-1]=insert;
	for (int i=0;i<=elements;i++)
	{
		printf("%d",arr[i]);
		fflush(stdin);fflush(stdout);
	}
}

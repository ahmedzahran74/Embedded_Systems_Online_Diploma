/*
 * finding the length of a string.c
 *
 *  Created on: Jun 30, 2022
 *      Author: AM
 */


#include"stdio.h"
int main()
{
	char string[100];
	int number=0;
	printf("enter a string: ");
	fflush(stdin);fflush(stdout);
	gets(string);
	for (int i=0;string[i]!=0;i++)
	{
		number ++;
	}
	printf("the string length is %d",number);
	fflush(stdin);fflush(stdout);
}

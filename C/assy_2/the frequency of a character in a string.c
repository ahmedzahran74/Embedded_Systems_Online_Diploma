/*
 * the frequency of a character in a string.c
 *
 *  Created on: Jun 30, 2022
 *      Author: AM
 */


#include"stdio.h"
int main()
{
	char string [100];
	char c;
	int frequency=0;
	printf("enter a string: ");
	fflush(stdin);fflush(stdout);
	gets(string);
	printf("enter a character to find the frequency: ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&c);
	for(int i=0;string[i]!=0;i++)
	{
		if(c== string[i])
		frequency++;
	}
	printf("frequency of %c is %d",c,frequency);
	fflush(stdin);fflush(stdout);
}

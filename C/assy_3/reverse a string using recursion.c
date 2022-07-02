/*
 * reverse a string using recursion.c
 *
 *  Created on: Jul 2, 2022
 *      Author: AM
 */

#include"stdio.h"
void reverse_string()
{
	char c;
	scanf("%c",&c);
	if(c!='\n')
	{
		reverse_string();
		printf("%c",c);
		fflush(stdin);fflush(stdout);
	}
}
int main()
{
	printf("enter a string:\n");
	fflush(stdin);fflush(stdout);
	reverse_string();
}

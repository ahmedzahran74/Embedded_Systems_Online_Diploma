/*
 * finding the length of a string.c
 *
 *  Created on: Jun 30, 2022
 *      Author: AM
 */


#include"stdio.h"
#define N 100
void getting_string (char *str,int n)
{
	char ch;
	char flag=0;
	for (int i=0;i<n;i++)
	{
		if ((ch=getchar())!='\n')
			str[i]=ch;
		else
		{
			str[i]=0;
			break;
			flag=1;
		}
	}
	if (flag==0)
	str[N]='\0';

}
int getting_string_length(char *str)
{
	int number=0;
	for (int i=0;str[i]!=0;i++)
	{
		number ++;
	}
	return number;
}
int main()
{
	char string[N];
	int length;
	printf("enter a string");
	fflush(stdin);fflush(stdout);
	getting_string (string,N-1);
	length=getting_string_length(string);
	printf("the string length is %d",length);
	fflush(stdin);fflush(stdout);
}

/*
 * asyy5_3.c
 *
 *  Created on: Jul 13, 2022
 *      Author: AM
 */

#include "stdio.h"
void getting_string (char*str,int n);
int getting_string_length(char *str);
int main()
{
	char str[100];
	printf("Enter a string in reverse order :\n");
	fflush(stdin);fflush(stdout);
	getting_string(str,99);
	int length=getting_string_length(str);
	printf("Reverse of the string is : \n");
	fflush(stdin);fflush(stdout);
	for(int i=length-1;i>=0;i--)
	{
		printf("%c",str[i]);
	}
}
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
			flag=1;
			break;

		}
	}
	if (flag==0)
	str[n]='\0';

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

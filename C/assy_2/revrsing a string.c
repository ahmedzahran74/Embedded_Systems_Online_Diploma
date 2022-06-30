/*
 * test.c
 *
 *  Created on: Jun 29, 2022
 *      Author: AM
 */


#include "stdio.h"
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
void main (int argc,char **argv)
{
	char string[N];
	int length;
	int last_element;
	printf("enter the string");
	fflush(stdin);fflush(stdout);
	getting_string(string,N);
	length=getting_string_length(string);
	last_element=(int)(round(length/2.0));
	for(int i=length-1;i>=last_element;i--)
	{
		string[i]+=string[length-i-1];
		string[length-i-1]=string[i]-string[length-i-1];
		string[i]-=string[length-i-1];
	}

		printf("%s",string);
		fflush(stdin);fflush(stdout);

}


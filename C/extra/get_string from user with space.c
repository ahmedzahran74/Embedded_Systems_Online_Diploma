/*
 * test.c
 *
 *  Created on: Jun 29, 2022
 *      Author: AM
 */


#include "stdio.h"
#define N 10
void fun (char *str,int n)
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
void main (int argc,char **argv)
{
	char s[N+1];
	fun(s,N);
	printf("%s",s);
	fflush(stdin);fflush(stdout);

}


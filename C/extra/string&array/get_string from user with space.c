/*
 * test.c
 *
 *  Created on: Jun 29, 2022
 *      Author: AM
 */


#include "stdio.h"
#define N 10
void getting_string(char *str,int n)
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
	str[n]='\0';

}
void main (int argc,char **argv)
{
	char s[N+1];
	getting_string(s,N);
	printf("%s",s);
	fflush(stdin);fflush(stdout);

}


/*
 * from hexa to decimal.c
 *
 *  Created on: Jul 2, 2022
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
int power(int x,int y)
{
	int result=1;
	for (int i=1;i<=y;i++)
	{
		result*=x;
	}
	return result;
}
int from_Hexa_to_decimal(char* str)
{
	int length,result=0;
	char c;
	length=getting_string_length(str);
	for(int i=length-1;i>=0;i--)
	{
		c=str[i];
		if(c>=65&&c<=70)
		{
			result+=(c-55)*power(16,length-(i+1));
		}
		else if(c>=97&&c<=102)
		{
			result+=(c-87)*power(16,length-(i+1));
		}
		else if(c>=48&&c<=57)
		{
			result+=(c-48)*power(16,length-(i+1));
		}
	}
	return result;
}
int main()
{
	char string[N];
	int result;
	printf("enter a number in hexadecimal: ");
	fflush(stdin);fflush(stdout);
	scanf("%s",string);
	result=from_Hexa_to_decimal(string);
	printf("%s in decimal is %d",string,result);
	fflush(stdin);fflush(stdout);
}


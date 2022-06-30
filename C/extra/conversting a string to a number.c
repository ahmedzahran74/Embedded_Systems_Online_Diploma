/*
 * test.c
 *
 *  Created on: Jun 29, 2022
 *      Author: AM
 */


#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int power(int x,int y);//calculating x power y

int no_of_string_char(char *s);//counting the number of string char

void main (int argc,char **argv)
{

	char s[100];
	char x;
	int n,size;
	int number=0;
	printf("enter the distance in KM \n");
	fflush(stdin);fflush(stdout);
	scanf("%s",s);
	size=no_of_string_char(s);
	//size=sizeof(s);

	for (int i=size-1;i>=0;i--)
	{

		x=s[i];
		n=(int)x-48;
		number+=n*power(10,size-1-i);
	}
	printf("you entered %d",number);
	fflush(stdin);fflush(stdout);

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
int no_of_string_char(char *s)
{
	int size=0;
	for (int i=0;s[i]!=0;i++)
		size++;
	return size;
}

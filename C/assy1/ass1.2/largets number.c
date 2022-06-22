/*
 * largets number.c
 *
 *  Created on: Jun 22, 2022
 *      Author: Ahmed Zahran
 */


#include "stdio.h"
void main (int argc,char **argv)
{
	float a,b,c;
	printf("enter 3 numbers to get the largest\n");
	fflush(stdin);fflush(stdout);
	scanf("%f%f%f",&a,&b,&c);
	if(a>b)
	{
		if(a>c)
		{
			printf("%f is the largest number",a);
			fflush(stdin);fflush(stdout);
		}
		else
		{
			printf("%f is the largest number",c);
			fflush(stdin);fflush(stdout);
		}
	}
	else
	{
		if(b>c)
		{
			printf("%f is the largest number",b);
			fflush(stdin);fflush(stdout);
		}
		else
		{
			printf("%f is the largest number",c);
			fflush(stdin);fflush(stdout);
		}
	}
}

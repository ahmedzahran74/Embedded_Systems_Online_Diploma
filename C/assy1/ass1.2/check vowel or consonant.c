/*
 * check vowel or consonant.c
 *
 *  Created on: Jun 22, 2022
 *      Author: Ahmed Zahran
 */


#include "stdio.h"
void main (int argc,char **argv)
{
	char c;
	int i;
	do
	{
		printf("enter a leeter you want to check\n");
		fflush(stdin);fflush(stdout);
		scanf("%c",&c);
		if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
		{
			printf("The letter is vowel\n");
			fflush(stdin);fflush(stdout);
		}
		else
		{
			printf("the letter is consonant\n");
			fflush(stdin);fflush(stdout);
		}
		printf("enter 1 to continue other to break \n");
		fflush(stdin);fflush(stdout);
		scanf("%d",&i);
	}while(i=1);
}

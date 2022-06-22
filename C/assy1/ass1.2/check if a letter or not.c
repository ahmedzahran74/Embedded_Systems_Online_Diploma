/*
 * check if a letter or not.c
 *
 *  Created on: Jun 22, 2022
 *      Author: Ahmed Zahran
 */


#include "stdio.h"
void main (int argc,char **argv)
{
	char c,i;
	do
	{

		printf("enter a character you want to check\n");
		fflush(stdin);fflush(stdout);
		scanf("%c",&c);
		if(c>='a'&&c<='z'||c>='A'&&c<='Z')
		{
			printf("%c is a letter\n",c);
			fflush(stdin);fflush(stdout);
		}
		else
		{
			printf("%c isn't a letter\n",c);
			fflush(stdin);fflush(stdout);
		}
		printf("enter 1 to continue and other to break\n");
		fflush(stdin);fflush(stdout);
		scanf("%d",&i);
	}while(i=1);
}

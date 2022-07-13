/*
 * assy5_2.c
 *
 *  Created on: Jul 13, 2022
 *      Author: AM
 */


#include "stdio.h"

int main()
{
	char alph[27];
	char*ptr;
	ptr=alph;
	for(int i=0;i<26;i++)
	{
		*(ptr+i)='A'+i;
	}
	printf("The Alphabets are : \n");
	for(int i=0;i<26;i++)
	{
		printf("%c\t",*(ptr+i));
	}
}

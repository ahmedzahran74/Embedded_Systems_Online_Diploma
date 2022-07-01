/*
 * matrix_transpose.c
 *
 *  Created on: Jun 29, 2022
 *      Author: AM
 */


#include "stdio.h"
void main (int argc,char **argv)
{
	int matrix[3][3];
	for (int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("enter the element of (%d,%d)",i,j);
			fflush(stdin);fflush(stdout);
			scanf("%d",&matrix[i][j]);
		}
	}
	printf("your matrix \n");
	fflush(stdin);fflush(stdout);
	for (int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%d\t",matrix[i][j]);
			fflush(stdin);fflush(stdout);
		}
		printf("\n");
		fflush(stdin);fflush(stdout);
	}
	for (int i=0;i<2;i++)
	{
		for(int j=1;j<3;j++)
		{
			if (i==j)
				continue;//if you don't use this statement the middle element will be zero
			matrix[i][j]+=matrix[j][i];
			matrix[j][i]=matrix[i][j]-matrix[j][i];
			matrix[i][j]-=matrix[j][i];
		}
	}
	printf("the inverse is \n");
	fflush(stdin);fflush(stdout);
	for (int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%d\t",matrix[i][j]);
			fflush(stdin);fflush(stdout);
		}
		printf("\n");
		fflush(stdin);fflush(stdout);
	}

}

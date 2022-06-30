/*
 * matrix transpose.c
 *
 *  Created on: Jun 30, 2022
 *      Author: AM
 */

#include"stdio.h"
int main()
{
	int matrix[10][10];
	int n_rows,n_columns;
	printf("enter the number of raws :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n_rows);
	printf("enter the number of columns :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n_columns);
	for (int i=0;i<n_rows;i++)
	{
		for (int j=0;j<n_columns;j++)
		{
			printf("enter the element a%d%d",i,j);
			fflush(stdin);fflush(stdout);
			scanf("%d",&matrix[i][j]);
		}
	}
	printf("you entered\n");
	fflush(stdin);fflush(stdout);
	for (int i=0;i<n_rows;i++)
	{
		printf("\n");
		fflush(stdin);fflush(stdout);
		for (int j=0;j<n_columns;j++)
		{
			printf("%d\t",matrix[i][j]);
			fflush(stdin);fflush(stdout);
		}
	}
	for (int i=0;i<n_rows;i++)
	{
		for(int j=1;j<n_columns;j++)
		{
			if(i==j)//as matrix(nn) element will not be changed its place
				continue;
			matrix[i][j]^=matrix[j][i];
			matrix[j][i]^=matrix[i][j];
			matrix[i][j]^=matrix[j][i];
		}
	}
	printf("\nthe transpose is \n");
	fflush(stdin);fflush(stdout);
	for (int i=0;i<n_columns;i++)
	{
		printf("\n");
		fflush(stdin);fflush(stdout);
		for (int j=0;j<n_rows;j++)
		{
			printf("%d\t",matrix[i][j]);
			fflush(stdin);fflush(stdout);
		}
	}
}

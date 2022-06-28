/*
 * qq.c
 *
 *  Created on: Jun 28, 2022
 *      Author: AM
 */


#include "stdio.h"
#define N 5
void main (int argc,char **argv)
{
	int rawsa,columnsa,rawsb,columnsb,sum;
	printf("enter the number of raws of matrix a");
	fflush(stdin);fflush(stdout);
	scanf("%d",&rawsa);
	printf("enter the number of columns of matrix a");
	fflush(stdin);fflush(stdout);
	scanf("%d",&columnsa);
	printf("enter the number of raws of matrix b");
	fflush(stdin);fflush(stdout);
	scanf("%d",&rawsb);
	printf("enter the number of columns of matrix a");
	fflush(stdin);fflush(stdout);
	scanf("%d",&columnsb);
	if(columnsa==rawsb)
	{
		int a[rawsa][columnsa];
		int b[rawsb][columnsb];
		int result[rawsa][columnsb];
		for (int i=0;i<rawsa;i++)
		{
			for(int j=0;j<columnsa;j++)
			{
				printf("enter the first matrix element a[%d][%d]",i,j);
				fflush(stdin);fflush(stdout);
				scanf("%d",&a[i][j]);
			}
		}
		for (int i=0;i<rawsb;i++)
		{
			for(int j=0;j<columnsb;j++)
			{
				printf("enter the second matrix element b[%d][%d]",i,j);
				fflush(stdin);fflush(stdout);
				scanf("%d",&b[i][j]);
			}
		}
		for (int i=0;i<rawsa;i++)
		{
			for (int j=0;j<columnsb;j++)
			{
				sum=0;
				for(int k=0;k<rawsb;k++)
				{
					sum+=a[i][k]*b[k][j];
					result[i][j]=sum;
				}
			}
		}
		for (int i=0;i<rawsa;i++)
		{
			for(int j=0;j<columnsb;j++)
			{
				printf("%d\t",result[i][j]);
				fflush(stdin);fflush(stdout);
			}
			printf("\n");
		}
	}
}

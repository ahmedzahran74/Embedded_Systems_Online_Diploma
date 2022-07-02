/*
 * test.c
 *
 *  Created on: Jul 1, 2022
 *      Author: AM
 */


#include<stdio.h>
#define N_ROWS 15
#define N_COLUMNS (2*N_ROWS-1)
int main()
{
	for (int i=0;i<N_ROWS;i++)
	{
		for(int j=0;j<N_COLUMNS;j++)
		{
			if(j>=(N_COLUMNS/2-i)&&j<=(N_COLUMNS/2+i))
			{
				printf("*");
				fflush(stdin);fflush(stdout);
			}
			else{
				printf(" ");
				fflush(stdin);fflush(stdout);
			}
		}
		printf("\n");
		fflush(stdin);fflush(stdout);
	}
	return 0;
}

/*
 * addition of 2 matrices.c
 *
 *  Created on: Jun 30, 2022
 *      Author: AM
 */


/*
 * test.c
 *
 *  Created on: Jun 30, 2022
 *      Author: AM
 */


#include"stdio.h"
int main()
{
	float m_1[2][2];
	float m_2[2][2];
	float result[2][2];
	printf("enter the elements of the first array");
	fflush(stdin);fflush(stdout);
	for (int i=0;i<2;i++)
	{
		for (int j=0;j<2;j++)
		{
			printf("\nenter the element a%d%d:",i,j);
			fflush(stdin);fflush(stdout);
			scanf("%f",&m_1[i][j]);
		}
	}
	printf("\nenter the elements of the second array");
	for (int i=0;i<2;i++)
	{
		for (int j=0;j<2;j++)
		{
			printf("\nenter the element b%d%d:",i,j);
			fflush(stdin);fflush(stdout);
			scanf("%f",&m_2[i][j]);
		}
	}
	printf("sum of matrix is :\n");

	for (int i=0;i<2;i++)
	{
		for (int j=0;j<2;j++)
		{
			fflush(stdin);fflush(stdout);
			printf("%.2f\t",m_1[i][j]+m_2[i][j]);
			fflush(stdin);fflush(stdout);
		}
		printf("\n");
		fflush(stdin);fflush(stdout);
	}
}

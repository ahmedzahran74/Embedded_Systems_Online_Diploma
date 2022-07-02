/*
 * floyd's_triangle.c
 *
 *  Created on: Jul 2, 2022
 *      Author: AM
 */


#include"stdio.h"
void floyd_triangle(int rows,int columns)
{
	int number=1;
	for(int i=0;i<rows;i++)
	{
		for (int j=0;j<columns;j++)
		{
			if(j<=i)
				printf("%d\t",number++);
		}
		printf("\n");
	}
}
int main()
{
	floyd_triangle(4,5);
}

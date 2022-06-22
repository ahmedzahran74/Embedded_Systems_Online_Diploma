/*
 * main.c
 *
 *  Created on: Jun 21, 2022
 *      Author: Ahmed Zahran
 */

#include "stdio.h"

void main (int argc,char **argv)
{
	int x;
	printf("Enter a integer: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
	printf("You entered: %d",x);
}

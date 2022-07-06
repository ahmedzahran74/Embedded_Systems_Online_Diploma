/*
 * 4_5.c
 *
 *  Created on: Jul 6, 2022
 *      Author: AM
 */

#include "math.h"
#include "stdio.h"
#define CIRCLE_AREA(r)	M_PI*r*r
int main()
{
	float r;
	printf("Enter the circle raduis");
	fflush(stdin);fflush(stdout);
	scanf("%f",&r);
	printf("%f",CIRCLE_AREA(r));
	fflush(stdin);fflush(stdout);
}

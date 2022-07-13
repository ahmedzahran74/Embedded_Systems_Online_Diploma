/*
 * assy5_1.c
 *
 *  Created on: Jul 13, 2022
 *      Author: AM
 */


#include "stdio.h"
int main()
{
	int m =29;
	printf("Address of m %p : \n",&m);
	printf("Value of m : %d : \n",m);
	int*ab=&m;
	printf("Now ab is assigned with the address of m\n");
	printf("Address of pointer ab : %p\n",ab);
	printf("Content of pointer ab : %d\n",*ab);
	m=34;
	printf("The value of m assigned to %d now.\n",m);
	printf("Address of pointer ab : %p\n",ab);
	printf("Content of pointer ab : %d\n",*ab);
	*ab=7;
	printf("The pointer variable ab is assigned with the value %d now.\n",*ab);
	printf("Address of m : %p\n",&m);
	printf("Value of m : %d",m);
}

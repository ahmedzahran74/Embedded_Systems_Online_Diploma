/*
 * main.c
 *
 *  Created on: Aug 5, 2022
 *      Author: AM
 */
#include "CA.h"

void setup()
{
	//make setup
	state=STATE(waiting);
}
int main()
{
	setup();
	while(1)
	{
		state();
	}
}


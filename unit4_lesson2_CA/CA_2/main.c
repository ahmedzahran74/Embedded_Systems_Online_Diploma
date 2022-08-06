/*
 * main.c
 *
 *  Created on: Aug 6, 2022
 *      Author: AM
 */
#include"stdio.h"
#include "states.h"
#include "CA.h"
#include "US.h"
#include "DC.h"
extern void(*state)();
extern void(*US_State)();
extern void(*DC_State)();
void main_init();
void main()
{
	main_init();
	while(1)
	{
		US_State();
		state();
		DC_State();
		//for(int i=0;i<50000;i++);
	}
}
void main_init()
{
	state=STATE(waiting);
	US_State=STATE(US_busy);
	DC_State=STATE(DC_Idel);
}

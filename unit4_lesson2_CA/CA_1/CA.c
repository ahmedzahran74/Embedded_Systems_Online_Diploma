/*
 * CA.c
 *
 *  Created on: Aug 5, 2022
 *      Author: AM
 */
#include "CA.h"
#include <stdio.h>
enum{
	waiting,
	driving
}state_id;

//variables definitions
unsigned int distance,speed,threshould=50;


//global pointer to function definition
void(*state)();

STATE_define(waiting)
{
	speed=0;
	//read from ultrasonic sensor
	distance=generate_random(45,55,1);
	//check event
	(distance<=threshould) ? (state=STATE(waiting)):(state=STATE(driving));
	printf("waiting state: distance=%d	speed=%d \n",distance,speed);
}
STATE_define(driving)
{
	speed=30;
	//read from ultrasonic sensor
	distance=generate_random(45,55,1);
	//check event
	(distance<=threshould) ? (state=STATE(waiting)):(state=STATE(driving));
	printf("driving state: distance=%d	speed=%d \n",distance,speed);
}
int generate_random(int l,int r,int count)
{

	for (int i=0;i<count;i++)
	{
		int rand_num=(rand() %(r-l+1))+l;
		return rand_num;
	}
	return 0;
}


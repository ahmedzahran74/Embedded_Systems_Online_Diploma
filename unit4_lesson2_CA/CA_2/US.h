/*
 * US.h
 *
 *  Created on: Aug 6, 2022
 *      Author: AM
 */

#ifndef US_H_
#define US_H_
#include "states.h"
enum{
	US_busy,
	US_idel
}US_State_Id;
extern void set_distance(int d);
extern unsigned int distance;
STATE_define(US_busy);
int generate_random(int l,int r,int count);

#endif /* US_H_ */

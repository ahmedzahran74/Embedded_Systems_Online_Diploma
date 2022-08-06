/*
 * CA.h
 *
 *  Created on: Aug 5, 2022
 *      Author: AM
 */

#ifndef CA_H_
#define CA_H_
//prototype definitions
#define STATE_define(_State_Fun_)	void ST_##_State_Fun_()
#define STATE(_State_Func_) ST_##_State_Func_
int generate_random(int l,int r,int count);
STATE_define(waiting);
STATE_define(driving);


extern void (*state)();
#endif /* CA_H_ */

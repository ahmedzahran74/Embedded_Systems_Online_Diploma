/*
 * DC.h
 *
 *  Created on: Aug 6, 2022
 *      Author: AM
 */

#ifndef DC_H_
#define DC_H_
#include"states.h"
enum{
	DC_busy,
	DC_idel
}DC_state_id;
extern int speed;
void Set_Speed(int s);
STATE_define(DC_Idel);
STATE_define(DC_Busy);
#endif /* DC_H_ */

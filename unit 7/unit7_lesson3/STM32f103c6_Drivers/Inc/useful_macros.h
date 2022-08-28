/*
 * useful_macros.h
 *
 *  Created on: Aug 27, 2022
 *      Author: AM
 */

#ifndef INC_USEFUL_MACROS_H_
#define INC_USEFUL_MACROS_H_
#define SET_BIT(REG,POS)			REG|=(1<<POS)
#define CLEAR_BITS(REG,POS,NUM) 	{\
									if(NUM==1)REG&=~(1<<POS);\
									else if(NUM==2)REG&=~(0b11<<POS);\
									else if(NUM==3)REG&=~(0b111<<POS);\
									else if(NUM==4)REG&=~(0xf<<POS);\
									}
#define	PUT_VALUE_IN_REG(REG,VALUE,POSTITION)	REG|=VALUE<<POSTITION//the configured bits should be contains zeros
																	 //before use this macro
#define TOGGLE_BIT(REG,POSITION)	REG^=(1<<POSITION)
#define GET_BIT(REG,POSITION)		((REG>>POSITION) & (0X1))
#define HIGH 						1
#define LOW 						0

#endif /* INC_USEFUL_MACROS_H_ */

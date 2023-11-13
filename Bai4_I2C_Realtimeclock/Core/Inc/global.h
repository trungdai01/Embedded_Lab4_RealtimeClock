/*
 * global.h
 *
 *  Created on: Nov 8, 2023
 *      Author: quoct
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define MODE                0

#define INIT                1
#define NORMAL              2


#define EDIT_HOUR           3
#define EDIT_MIN            4
#define EDIT_SEC            5


#define SET_TIMER_HOUR      6
#define SET_TIMER_MIN       7
#define SET_TIMER_SEC       8
#define SAVE_SETTING        10

extern int status;

void blinky();

#endif /* INC_GLOBAL_H_ */

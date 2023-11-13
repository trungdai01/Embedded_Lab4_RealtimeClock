/*
 * global.h
 *
 *  Created on: Nov 8, 2023
 *      Author: quoct
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "utils.h"
#include "ds3231.h"
#include "lcd.h"
#include "button.h"
#include "led_7seg.h"
#include "picture.h"

#define MODE1 1
#define MODE2 2
#define MODE3 3
#define MODE4 4
#define MODE5 5
#define MODE6 6
#define MODE7 7
#define MODE8 8

#define NUM_OF_BUT 4
#define BUTTON1 0
#define BUTTON2 1
#define BUTTON3 2
#define BUTTON4 3

#define INIT 0
#define NORMAL 1

#define EDIT_HOUR 2
#define EDIT_MIN 3
#define EDIT_SEC 4

#define SAVE_SETTING 5

extern int statusNORMAL_1;
extern int statusNORMAL_2;
extern int statusSEC_1; // Blink seconds
extern int statusSEC_2; // Increase
extern int statusSEC_3; // Decrease
extern int statusSEC_4; // Save setting

extern int statusMIN_1;
extern int statusMIN_2;
extern int statusMIN_3;
extern int statusMIN_4;

extern int statusHOUR_1;
extern int statusHOUR_2;
extern int statusHOUR_3;
extern int statusHOUR_4;

extern int statusDAY_1;
extern int statusDAY_2;
extern int statusDAY_3;
extern int statusDAY_4;

extern int statusDATE_1;
extern int statusDATE_2;
extern int statusDATE_3;
extern int statusDATE_4;

extern int statusMONTH_1;
extern int statusMONTH_2;
extern int statusMONTH_3;
extern int statusMONTH_4;

extern int statusYEAR_1;
extern int statusYEAR_2;
extern int statusYEAR_3;
extern int statusYEAR_4;

extern int mode;

extern int SEC;
extern int MIN;
extern int HOUR;
extern int DAY;
extern int DATE;
extern int MONTH;
extern int YEAR0;

extern uint8_t counterSec;
extern uint8_t counterMin;
extern uint8_t counterHour;
extern uint8_t counterDay;
extern uint8_t counterDate;
extern uint8_t counterMonth;
extern uint8_t counterYear;

void initTime();
void init_value();
void blinky();
void displayTime();

#endif /* INC_GLOBAL_H_ */

#include "global.h"

int statusNORMAL;
int statusSEC_1 = 0; //Blink seconds
int statusSEC_2 = 0; //Increase
int statusSEC_3 = 0; //Decrease
int statusSEC_4 = 0; //Save settings

int statusMIN_1 = 0;
int statusMIN_2 = 0;
int statusMIN_3 = 0;
int statusMIN_4 = 0;

int statusHOUR_1 = 0;
int statusHOUR_2 = 0;
int statusHOUR_3 = 0;
int statusHOUR_4 = 0;

int statusDAY_1 = 0;
int statusDAY_2 = 0;
int statusDAY_3 = 0;
int statusDAY_4 = 0;

int statusDATE_1 = 0;
int statusDATE_2 = 0;
int statusDATE_3 = 0;
int statusDATE_4 = 0;

int statusMONTH_1 = 0;
int statusMONTH_2 = 0;
int statusMONTH_3 = 0;
int statusMONTH_4 = 0;

int statusYEAR_1 = 0;
int statusYEAR_2 = 0;
int statusYEAR_3 = 0;
int statusYEAR_4 = 0;

int mode = 0;

int SEC = 0;
int MIN = 0;
int HOUR = 0;
int DAY = 0;
int DATE = 0;
int MONTH = 0;
int YEAR = 0;

uint8_t counterSec = 0;
uint8_t counterMin = 0;
uint8_t counterHour = 0;
uint8_t counterDay = 0;
uint8_t counterDate = 0;
uint8_t counterMonth = 0;
uint8_t counterYear = 0;

void initTime(void)
{
    SEC = 0;
    MIN = 50;
    HOUR = 6;
    DAY = 6;
    DATE = 22;
    MONTH = 2;
    YEAR = 22;
}

void init_value(void)
{
    mode = MODE1;

    statusNORMAL = INIT;
    statusSEC_1 = INIT;
    statusSEC_2 = INIT;
    statusSEC_3 = INIT;
    statusSEC_4 = INIT;

    statusMIN_1 = INIT;
    statusMIN_2 = INIT;
    statusMIN_3 = INIT;
    statusMIN_4 = INIT;

    statusHOUR_1 = INIT;
    statusHOUR_2 = INIT;
    statusHOUR_3 = INIT;
    statusHOUR_4 = INIT;

    statusDAY_1 = INIT;
    statusDAY_2 = INIT;
    statusDAY_3 = INIT;
    statusDAY_4 = INIT;

    statusDATE_1 = INIT;
    statusDATE_2 = INIT;
    statusDATE_3 = INIT;
    statusDATE_4 = INIT;
    
    statusMONTH_1 = INIT;
    statusMONTH_2 = INIT;
    statusMONTH_3 = INIT;
    statusMONTH_4 = INIT;

    statusYEAR_1 = INIT;
    statusYEAR_2 = INIT;
    statusYEAR_3 = INIT;
    statusYEAR_4 = INIT;

    counterSec = SEC;
    counterMin = MIN;
    counterHour = HOUR;
    counterDay = DAY;
    counterDate = DATE;
    counterMonth = MONTH;
    counterYear = YEAR;
}

void blinky()
{
    
}

void displayTime()
{
	lcd_ShowIntNum(70, 100, ds3231_hours, 2, GREEN, BLACK, 24);
	lcd_ShowIntNum(110, 100, ds3231_min, 2, GREEN, BLACK, 24);
	lcd_ShowIntNum(150, 100, ds3231_sec, 2, GREEN, BLACK, 24);
	lcd_ShowIntNum(20, 130, ds3231_day, 2, YELLOW, BLACK, 24);
	lcd_ShowIntNum(70, 130, ds3231_date, 2, YELLOW, BLACK, 24);
	lcd_ShowIntNum(110, 130, ds3231_month, 2, YELLOW, BLACK, 24);
	lcd_ShowIntNum(150, 130, ds3231_year, 2, YELLOW, BLACK, 24);
}
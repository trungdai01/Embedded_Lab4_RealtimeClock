#include "global.h"

int statusNORMAL_1;
int statusNORMAL_2;
int statusSEC_1 = 0; // Blink seconds
int statusSEC_2 = 0; // Increase
int statusSEC_3 = 0; // Save settings

int statusMIN_1 = 0;
int statusMIN_2 = 0;
int statusMIN_3 = 0;

int statusHOUR_1 = 0;
int statusHOUR_2 = 0;
int statusHOUR_3 = 0;

int statusDAY_1 = 0;
int statusDAY_2 = 0;
int statusDAY_3 = 0;

int statusDATE_1 = 0;
int statusDATE_2 = 0;
int statusDATE_3 = 0;

int statusMONTH_1 = 0;
int statusMONTH_2 = 0;
int statusMONTH_3 = 0;

int statusYEAR_1 = 0;
int statusYEAR_2 = 0;
int statusYEAR_3 = 0;

int statusNORMAL_ALARM = 0;

int statusHOUR_ALARM_1 = 0;
int statusHOUR_ALARM_2 = 0;
int statusHOUR_ALARM_3 = 0;

int statusMIN_ALARM_1 = 0;
int statusMIN_ALARM_2 = 0;
int statusMIN_ALARM_3 = 0;

int mode = 0;
int mode_alarm = 0;

uint8_t counterSec = 0;
uint8_t counterMin = 0;
uint8_t counterHour = 0;
uint8_t counterDay = 0;
uint8_t counterDate = 0;
uint8_t counterMonth = 0;
uint8_t counterYear = 0;
uint8_t counterHour_Alarm = 0;
uint8_t counterMin_Alarm = 0;
uint8_t counter_blink1 = 0;
uint8_t counter_blink2 = 0;

uint8_t counter_alert1 = 0;
uint8_t counter_alert2 = 0;

uint8_t saveTime[7] = {0};

void init_value(void)
{
    mode = MODE1;
    mode_alarm = ALARM_MODE1;

    statusNORMAL_1 = INIT;
    statusNORMAL_2 = INIT;
    statusSEC_1 = INIT;
    statusSEC_2 = INIT;
    statusSEC_3 = INIT;

    statusMIN_1 = INIT;
    statusMIN_2 = INIT;
    statusMIN_3 = INIT;

    statusHOUR_1 = INIT;
    statusHOUR_2 = INIT;
    statusHOUR_3 = INIT;

    statusDAY_1 = INIT;
    statusDAY_2 = INIT;
    statusDAY_3 = INIT;

    statusDATE_1 = INIT;
    statusDATE_2 = INIT;
    statusDATE_3 = INIT;

    statusMONTH_1 = INIT;
    statusMONTH_2 = INIT;
    statusMONTH_3 = INIT;

    statusYEAR_1 = INIT;
    statusYEAR_2 = INIT;
    statusYEAR_3 = INIT;

    statusHOUR_ALARM_1 = INIT;
    statusHOUR_ALARM_2 = INIT;
    statusHOUR_ALARM_3 = INIT;

    statusMIN_ALARM_1 = INIT;
    statusMIN_ALARM_2 = INIT;
    statusMIN_ALARM_3 = INIT;

    counter_blink1 = INIT;
    counter_blink2 = INIT;

    counter_alert1 = INIT;
    counter_alert2 = INIT;
}

void init_counter(void)
{
    counterSec = ds3231_sec;
    counterMin = ds3231_min;
    counterHour = ds3231_hours;
    counterDay = ds3231_day;
    counterDate = ds3231_date;
    counterMonth = ds3231_month;
    counterYear = ds3231_year;
}

void init_counter_alarm(void)
{
    counterHour_Alarm = ds3231_alarm_hour;
    counterMin_Alarm = ds3231_alarm_min;
}

void blinky(int unit)
{

    counter_blink1 = (counter_blink1 + 1) % 5;
    counter_blink2 = (counter_blink2 + 1) % 10;
    if (unit == HOUR)
    {
        if (counter_blink1 == 0)
        {
            lcd_ShowIntNum(70, 100, counterHour, 2, GREEN, BLACK, 24);
        }
        if (counter_blink2 == 0)
        {
            lcd_ShowIntNum(70, 100, 0, 2, BLACK, BLACK, 24);
        }
    }
    if (unit == MIN)
    {
        if (counter_blink1 == 0)
        {
            lcd_ShowIntNum(110, 100, counterMin, 2, GREEN, BLACK, 24);
        }
        if (counter_blink2 == 0)
        {
            lcd_ShowIntNum(110, 100, 0, 2, BLACK, BLACK, 24);
        }
    }
    if (unit == SEC)
    {
        if (counter_blink1 == 0)
        {
            lcd_ShowIntNum(150, 100, counterSec, 2, GREEN, BLACK, 24);
        }
        if (counter_blink2 == 0)
        {
            lcd_ShowIntNum(150, 100, 0, 2, BLACK, BLACK, 24);
        }
    }
    if (unit == DAY)
    {
        if (counter_blink1 == 0)
        {
            lcd_ShowIntNum(20, 130, counterDay, 2, YELLOW, BLACK, 24);
        }
        if (counter_blink2 == 0)
        {
            lcd_ShowIntNum(20, 130, 0, 2, BLACK, BLACK, 24);
        }
    }
    if (unit == DATE)
    {
        if (counter_blink1 == 0)
        {
            lcd_ShowIntNum(70, 130, counterDate, 2, YELLOW, BLACK, 24);
        }
        if (counter_blink2 == 0)
        {
            lcd_ShowIntNum(70, 130, 0, 2, BLACK, BLACK, 24);
        }
    }
    if (unit == MONTH)
    {
        if (counter_blink1 == 0)
        {
            lcd_ShowIntNum(110, 130, counterMonth, 2, YELLOW, BLACK, 24);
        }
        if (counter_blink2 == 0)
        {
            lcd_ShowIntNum(110, 130, 0, 2, BLACK, BLACK, 24);
        }
    }
    if (unit == YEAR)
    {
        if (counter_blink1 == 0)
        {
            lcd_ShowIntNum(150, 130, counterYear, 2, YELLOW, BLACK, 24);
        }
        if (counter_blink2 == 0)
        {
            lcd_ShowIntNum(150, 130, 0, 2, BLACK, BLACK, 24);
        }
    }
}

void blinkyAlarm(int unit)
{
    counter_alert1 = (counter_alert1 + 1) % 5;
    counter_alert2 = (counter_alert2 + 1) % 10;
    if (unit == HOUR_A)
    {
        if (counter_alert1 == 0)
        {
            lcd_ShowIntNum(70, 200, counterHour_Alarm, 2, BLUE, BLACK, 24);
        }
        if (counter_alert2 == 0)
        {
            lcd_ShowIntNum(70, 200, 0, 2, BLACK, BLACK, 24);
        }
    }
    if (unit == MIN_A)
    {
        if (counter_alert1 == 0)
        {
            lcd_ShowIntNum(110, 200, counterMin_Alarm, 2, BLUE, BLACK, 24);
        }
        if (counter_alert2 == 0)
        {
            lcd_ShowIntNum(110, 200, 0, 2, BLACK, BLACK, 24);
        }
    }
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

void updateTime()
{
    ds3231_Write(ADDRESS_YEAR, 23);
    ds3231_Write(ADDRESS_MONTH, 10);
    ds3231_Write(ADDRESS_DATE, 15);
    ds3231_Write(ADDRESS_DAY, 6);
    ds3231_Write(ADDRESS_HOUR, 15);
    ds3231_Write(ADDRESS_MIN, 30);
    ds3231_Write(ADDRESS_SEC, 35);
}

void displayAlarm(void)
{
    lcd_ShowIntNum(70, 200, ds3231_alarm_hour, 2, BLUE, BLACK, 24);
    lcd_ShowIntNum(110, 200, ds3231_alarm_min, 2, BLUE, BLACK, 24);
}

void updateAlarm(void)
{
    ds3231_Write(ADDRESS_HOUR_ALARM, 0);
    ds3231_Write(ADDRESS_MIN_ALARM, 0);
}

void alert(void)
{
    counter_alert1 = (counter_alert1 + 1) % 5;
    counter_alert2 = (counter_alert2 + 1) % 10;
    if (counter_alert1 == 0)
    {
        lcd_Clear(RED);
    }
    if (counter_alert2 == 0)
    {
        lcd_Clear(BLACK);
    }
}

// void resetSaveTime()
// {
//     for (int i = 0; i < 7; ++i)
//     {
//         saveTime[i] = 0;
//     }
// }

// void writeSaveTime()
// {
//     if (saveTime[0] == 1 || (counterHour != ds3231_hours))
//     {
//         ds3231_Write(ADDRESS_HOUR, counterHour);
//     }
//     if (saveTime[1] == 1 || (counterMin != ds3231_min))
//     {
//         ds3231_Write(ADDRESS_MIN, counterMin);
//     }
//     if (saveTime[2] == 1 || (counterSec != ds3231_sec))
//     {
//         ds3231_Write(ADDRESS_SEC, counterSec);
//     }
//     if (saveTime[3] == 1 || (counterDay != ds3231_day))
//     {
//         ds3231_Write(ADDRESS_DAY, counterDay);
//     }
//     if (saveTime[4] == 1 || (counterDate != ds3231_date))
//     {
//         ds3231_Write(ADDRESS_DATE, counterDate);
//     }
//     if (saveTime[5] == 1 || (counterMonth != ds3231_month))
//     {
//         ds3231_Write(ADDRESS_MONTH, counterMonth);
//     }
//     if (saveTime[6] == 1 || (counterYear != ds3231_year))
//     {
//         ds3231_Write(ADDRESS_YEAR, counterYear);
//     }
// }

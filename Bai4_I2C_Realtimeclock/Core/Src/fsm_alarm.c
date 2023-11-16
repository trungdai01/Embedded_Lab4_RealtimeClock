/*
 * fsm_alarm.c
 *
 *  Created on: Nov 15, 2023
 *      Author: quoct
 */
#include "fsm_alarm.h"
void fsm_alarm(void)
{
    if (mode_alarm == ALARM_MODE1)
    {
        switch (statusNORMAL_ALARM)
        {
        case INIT:
            statusNORMAL_ALARM = NORMAL;
            break;
        case NORMAL:
            lcd_StrCenter(0, 180, "ALARM(HH:MM)", BLUE, WHITE, 16, 1);
            ds3231_ReadAlarm();
            displayAlarm();
            if (ds3231_alarm_hour == ds3231_hours && ds3231_alarm_min == ds3231_min)
            {
                alert();
            }
            break;
        default:
            break;
        }
    }
    if (mode_alarm == ALARM_MODE2)
    {
        switch (statusHOUR_ALARM_1)
        {
        case INIT:
            statusHOUR_ALARM_1 = NORMAL;
            break;
        case NORMAL:
            blinkyAlarm(HOUR_A);
            break;
        default:
            break;
        }
        switch (statusHOUR_ALARM_2)
        {
        case INIT:
            statusHOUR_ALARM_2 = NORMAL;
            break;
        case NORMAL:
            if (button_count[3] == 1 || (button_count[3] > 40 && button_count[3] % 4 == 0))
            {
                counterHour_Alarm++;
                if (counterHour_Alarm >= 24)
                    counterHour_Alarm = 0;
            }
            break;
        default:
            break;
        }
        switch (statusHOUR_ALARM_3)
        {
        case INIT:
            statusHOUR_ALARM_3 = NORMAL;
            break;
        case NORMAL:
            if (button_count[12] == 1)
            {
                ds3231_Write(ADDRESS_HOUR_ALARM, counterHour_Alarm);
            }
            break;
        default:
            break;
        }
    }
    if (mode_alarm == ALARM_MODE3)
    {
        switch (statusMIN_ALARM_1)
        {
        case INIT:
            statusMIN_ALARM_1 = NORMAL;
            break;
        case NORMAL:
            blinkyAlarm(MIN_A);
            break;
        default:
            break;
        }
        switch (statusMIN_ALARM_2)
        {
        case INIT:
            statusMIN_ALARM_2 = NORMAL;
            break;
        case NORMAL:
            if (button_count[3] == 1 || (button_count[3] > 40 && button_count[3] % 4 == 0))
            {
                counterMin_Alarm++;
                if (counterMin_Alarm >= 60)
                    counterMin_Alarm = 0;
            }
            break;
        default:
            break;
        }
        switch (statusMIN_ALARM_3)
        {
        case INIT:
            statusMIN_ALARM_3 = NORMAL;
            break;
        case NORMAL:
            if (button_count[12] == 1)
            {
                ds3231_Write(ADDRESS_MIN_ALARM, counterMin_Alarm);
            }
            break;
        default:
            break;
        }
    }

    switch (mode_alarm)
    {
    case ALARM_MODE1:
        if (button_count[4] == 1)
        {
            mode_alarm = ALARM_MODE2;
            init_counter_alarm();
        }
        break;
    case ALARM_MODE2:
        if (button_count[4] == 1)
        {
            mode_alarm = ALARM_MODE3;
            lcd_ShowIntNum(70, 200, counterHour_Alarm, 2, BLUE, BLACK, 24);
        }
        break;
    case ALARM_MODE3:
        if (button_count[4] == 1)
        {
            mode_alarm = ALARM_MODE1;
            lcd_ShowIntNum(110, 200, counterMin_Alarm, 2, BLUE, BLACK, 24);
        }
        break;
    default:
        break;
    }
}

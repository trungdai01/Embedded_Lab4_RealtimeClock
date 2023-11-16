/*
 * fsm.c
 *
 *  Created on: Nov 8, 2023
 *      Author: quoct
 */

#include "fsm.h"
void fsm_clock()
{
    if (mode == MODE1)
    {
        switch (statusNORMAL_1)
        {
        case INIT:
            statusNORMAL_1 = NORMAL;
            break;
        case NORMAL:
            ds3231_ReadTime();
            displayTime();
            break;
        default:
            break;
        }
    }
    if (mode == MODE2)
    {
        switch (statusHOUR_1)
        {
        case INIT:
            statusHOUR_1 = NORMAL;
            break;
        case NORMAL:
            blinky(HOUR);
            break;
        default:
            break;
        }
        switch (statusHOUR_2)
        {
        case INIT:
            statusHOUR_2 = NORMAL;
            break;
        case NORMAL:
            if (button_count[3] == 1 || (button_count[3] > 40 && button_count[3] % 4 == 0))
            {
                counterHour++;
                if (counterHour >= 24)
                    counterHour = 0;
            }
            break;
        default:
            break;
        }
        switch (statusHOUR_3)
        {
        case INIT:
            statusHOUR_3 = NORMAL;
            break;
        case NORMAL:
            if (button_count[12] == 1)
            {
                saveTime[0] = 1;
            }
            break;
        default:
            break;
        }
    }
    if (mode == MODE3)
    {
        switch (statusMIN_1)
        {
        case INIT:
            statusMIN_1 = NORMAL;

            break;
        case NORMAL:
            blinky(MIN);
            break;
        default:
            break;
        }
        switch (statusMIN_2)
        {
        case INIT:
            statusMIN_2 = NORMAL;
            break;
        case NORMAL:
            if (button_count[3] == 1 || (button_count[3] > 40 && button_count[3] % 4 == 0))
            {
                counterMin++;
                if (counterMin >= 60)
                    counterMin = 0;
            }
            break;
        default:
            break;
        }
        switch (statusMIN_3)
        {
        case INIT:
            statusMIN_3 = NORMAL;
            break;
        case NORMAL:
            if (button_count[12] == 1)
            {
                saveTime[1] = 1;
            }
            break;
        default:
            break;
        }
    }
    if (mode == MODE4)
    {
        switch (statusSEC_1)
        {
        case INIT:
            statusSEC_1 = NORMAL;
            break;
        case NORMAL:
            blinky(SEC);
            break;
        default:
            break;
        }
        switch (statusSEC_2)
        {
        case INIT:
            statusSEC_2 = NORMAL;
            break;
        case NORMAL:
            if (button_count[3] == 1 || (button_count[3] > 40 && button_count[3] % 4 == 0))
            {
                counterSec++;
                if (counterSec >= 60)
                    counterSec = 0;
            }
            break;
        default:
            break;
        }
        switch (statusSEC_3)
        {
        case INIT:
            statusSEC_3 = NORMAL;
            break;
        case NORMAL:
            if (button_count[12] == 1)
            {
                saveTime[2] = 1;
            }
            break;
        default:
            break;
        }
    }
    if (mode == MODE5)
    {
        switch (statusDAY_1)
        {
        case INIT:
            statusDAY_1 = NORMAL;
            break;
        case NORMAL:
            blinky(DAY);
            break;
        default:
            break;
        }
        switch (statusDAY_2)
        {
        case INIT:
            statusDAY_2 = NORMAL;
            break;
        case NORMAL:
            if (button_count[3] == 1 || (button_count[3] > 40 && button_count[3] % 4 == 0))
            {
                counterDay++;
                if (counterDay >= 8)
                    counterDay = 1;
            }
            break;
        default:
            break;
        }
        switch (statusDAY_3)
        {
        case INIT:
            statusDAY_3 = NORMAL;
            break;
        case NORMAL:
            if (button_count[12] == 1)
            {
               saveTime[3] = 1;
            }
            break;
        default:
            break;
        }
    }
    if (mode == MODE6)
    {
        switch (statusDATE_1)
        {
        case INIT:
            statusDATE_1 = NORMAL;
            break;
        case NORMAL:
            blinky(DATE);
            break;
        default:
            break;
        }
        switch (statusDATE_2)
        {
        case INIT:
            statusDATE_2 = NORMAL;
            break;
        case NORMAL:
            if (button_count[3] == 1 || (button_count[3] > 40 && button_count[3] % 4 == 0))
            {
                counterDate++;
                if (counterDate >= 32)
                    counterDate = 1;
            }
            break;
        default:
            break;
        }
        switch (statusDATE_3)
        {
        case INIT:
            statusDATE_3 = NORMAL;
            break;
        case NORMAL:
            if (button_count[12] == 1)
            {
                saveTime[4] = 1;
            }
            break;
        default:
            break;
        }
    }
    if (mode == MODE7)
    {
        switch (statusMONTH_1)
        {
        case INIT:
            statusMONTH_1 = NORMAL;
            break;
        case NORMAL:
            blinky(MONTH);
            break;
        default:
            break;
        }
        switch (statusMONTH_2)
        {
        case INIT:
            statusMONTH_2 = NORMAL;
            break;
        case NORMAL:
            if (button_count[3] == 1 || (button_count[3] > 40 && button_count[3] % 4 == 0))
            {
                counterMonth++;
                if (counterMonth >= 13)
                    counterMonth = 1;
            }
            break;
        default:
            break;
        }
        switch (statusMONTH_3)
        {
        case INIT:
            statusMONTH_3 = NORMAL;
            break;
        case NORMAL:
            if (button_count[12] == 1)
            {
                saveTime[5] = 1;
            }
            break;
        default:
            break;
        }
    }
    if (mode == MODE8)
    {
        switch (statusYEAR_1)
        {
        case INIT:
            statusYEAR_1 = NORMAL;
            break;
        case NORMAL:
            blinky(YEAR);
            break;
        default:
            break;
        }
        switch (statusYEAR_2)
        {
        case INIT:
            statusYEAR_2 = NORMAL;
            break;
        case NORMAL:
            if (button_count[3] == 1 || (button_count[3] > 40 && button_count[3] % 4 == 0))
            {
                counterYear++;
                if (counterYear >= 100)
                    counterYear = 0;
            }
            break;
        default:
            break;
        }
        switch (statusYEAR_3)
        {
        case INIT:
            statusYEAR_3 = NORMAL;
            break;
        case NORMAL:
            if (button_count[12] == 1)
            {
                saveTime[6] = 1;
            }
            break;
        default:
            break;
        }
    }

    switch (mode)
    {
    case MODE1:
        if (button_count[0] == 1)
        {
            mode = MODE2;
            init_counter();
        }
        break;

    case MODE2:
        if (button_count[0] == 1)
        {
            mode = MODE3;
            lcd_ShowIntNum(70, 100, counterHour, 2, GREEN, BLACK, 24);
        }
        break;
    case MODE3:
        if (button_count[0] == 1)
        {
            mode = MODE4;
            lcd_ShowIntNum(110, 100, counterMin, 2, GREEN, BLACK, 24);
        }
        break;
    case MODE4:
        if (button_count[0] == 1)
        {
            mode = MODE5;
            lcd_ShowIntNum(150, 100, counterSec, 2, GREEN, BLACK, 24);
        }
        break;
    case MODE5:
        if (button_count[0] == 1)
        {
            mode = MODE6;
            lcd_ShowIntNum(20, 130, counterDay, 2, YELLOW, BLACK, 24);
        }
        break;
    case MODE6:
        if (button_count[0] == 1)
        {
            mode = MODE7;
            lcd_ShowIntNum(70, 130, counterDate, 2, YELLOW, BLACK, 24);
        }
        break;
    case MODE7:
        if (button_count[0] == 1)
        {
            mode = MODE8;
            lcd_ShowIntNum(110, 130, counterMonth, 2, YELLOW, BLACK, 24);
        }
        break;
    case MODE8:
        if (button_count[0] == 1)
        {
            writeSaveTime();
            mode = MODE1;
            lcd_ShowIntNum(150, 130, counterYear, 2, YELLOW, BLACK, 24);
            resetSaveTime();
        }
        break;
    default:
        break;
    }
}

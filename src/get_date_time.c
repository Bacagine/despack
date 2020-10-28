/* GitHub: 
 * 
 * Copyright (C) 2020
 * 
 * get_date_time.c: get date and time of system
 * 
 * Developed by Gustavo Bacagine <gustavo.bacagine@gmail.com>
 * 
 * Date of creation: 08/17/2020 */

#include "../include/package.h"

void
get_date_time(int *day, int *month,
              int *year, int *hour,
              int *minute, int *second){
    time_t tm_now;
    
    time(&tm_now);
    
    struct tm *local = localtime(&tm_now);
    
    *day = local->tm_mday;
    *month = local->tm_mon + 1;
    *year = local->tm_year + 1900;
    
    *hour = local->tm_hour;
    *minute = local->tm_min;
    *second = local->tm_sec;
}

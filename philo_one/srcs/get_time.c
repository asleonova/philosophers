#include "../includes/philo_one.h"

long    get_time_val(void)
{
    struct timeval time;
    long   msec;

    gettimeofday(&time, NULL);
    msec = time.tv_sec * 1000 + time.tv_usec / 1000;
    return(msec);

}
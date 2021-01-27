#include "../includes/philo_one.h"

void print_status(char *status, t_philo *philo, int game_over)
{
    long time;

    time = get_time_val() - g_start_time;
    pthread_mutex_lock(&g_print_status);
    printf("%ld %d %s\n", time, philo->philo_id, status);
    if (!game_over)
        pthread_mutex_unlock(&g_print_status);
}
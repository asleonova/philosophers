#include "../includes/philo_two.h"

void print_status(char *status, t_philo *philo, int game_over)
{
    long time;

    // (void)game_over;
    time = get_time_val() - g_start_time;
    sem_wait(g_print_status);
    printf("%ld %d %s\n", time, philo->philo_id, status);
    if (!game_over)
        sem_post(g_print_status);

}
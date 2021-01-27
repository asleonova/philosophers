#include "../includes/philo_one.h"

void    clean_and_destroy(t_sim *sim)
{
    int i;

    i = 0;
    pthread_mutex_destroy(&g_print_status);
    pthread_mutex_destroy(&g_check_death);
    while (i < sim->philo_num)
    {
        pthread_mutex_destroy(&sim->forks[i]);;
        i++;
    }
    free(sim->forks);
    free(sim->philos);

}
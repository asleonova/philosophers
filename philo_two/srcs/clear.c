#include "../includes/philo_two.h"

void    clean_and_destroy(t_sim *sim)
{
    int i;
    (void)sim;
    i = 0;
    sem_close(g_print_status);
    sem_close(g_check_death);
    sem_close(g_forks);
    // while (i < sim->philo_num)
    // {
    //     sem_close(g_forks);
    //     i++;
    // }
}
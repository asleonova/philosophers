#include "../includes/philo_one.h"

int main(int ac, char **av)
{
    t_sim sim;

    g_print_status = malloc(sizeof(pthread_mutex_t)); 
    g_start_time = get_time_val();
    if (parse_params(&sim, ac, av) == FAIL)
        return (FAIL);
    init_philo(&sim);
    int res;
    res = start_philo_thread(&sim);
    while (1)
    {
        ;
    }
    return(res);
}
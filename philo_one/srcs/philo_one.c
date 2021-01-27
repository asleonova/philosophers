#include "../includes/philo_one.h"

int is_full(t_sim *sim)
{
    int i;
    
    i = 0;
    while (i < sim->philo_num)
    {
        if (sim->philos[i].meal_count < sim->num_must_eat)
            return (0);
        i++;        
    }
    return (1);
}

int check_if_dead(t_sim *sim)
{
    int i;

    while (!is_dead)
    {
        i = 0;
        while (i < sim->philo_num)
        {
            pthread_mutex_lock(&g_check_death);
            if (sim->num_must_eat != 0 && is_full(sim))
            {
                print_status("All philosophers are full now. Game over!\n", &sim->philos[i], 1);
                is_dead = 1;
                return (0);
            }                
            else if (get_time_val() - sim->philos[i].start_eating > sim->philos[i].time_to_die)
            {
                print_status("died\n", &sim->philos[i], 1);
                is_dead = 1;
                return (0);
            }
            pthread_mutex_unlock(&g_check_death);
            i++;
        }
    }
    return (1);
}

int main(int ac, char **av)
{
    t_sim sim;

    is_dead = 0;
    pthread_mutex_init(&g_print_status, NULL);
    pthread_mutex_init(&g_check_death, NULL);
    g_start_time = get_time_val();
    if (parse_params(&sim, ac, av) == FAIL)
        return (FAIL);
    init_philo(&sim);
    int res;
    res = start_philo_thread(&sim);
    while (1) //while 1
    {
        usleep(2000);
        if (!check_if_dead(&sim))
            break;
    }
    // pthread_mutex_destroy(&g_check_death);
    // pthread_mutex_destroy(&g_print_status);
    return (res);
}

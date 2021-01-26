#include "../includes/philo_one.h"

void init_philo(t_sim *sim)
{
    int i;
    int count;

    count = sim->philo_num;
    i = 0;
    sim->philos = malloc(sizeof(t_philo) * count);
    sim->forks = malloc(sizeof(pthread_mutex_t) * sim->philo_num);
    //g_check_death = malloc(sizeof(pthread_mutex_t) * sim->philo_num); 
    while (i < count)
    {
        sim->philos[i].philo_id = i + 1;
        sim->philos[i].time_to_eat = sim->time_to_eat;
        sim->philos[i].philo_num = sim->philo_num;
        sim->philos[i].time_to_die = sim->time_to_die;
        sim->philos[i].time_to_sleep = sim->time_to_sleep;
        sim->philos[i].num_must_eat = sim->num_must_eat;
        sim->philos[i].is_dead = 1;
        sim->philos[i].left_fork = &sim->forks[i];
        if (i < count - 1)
            sim->philos[i].right_fork = &sim->forks[i + 1];
        else
            sim->philos[i].right_fork = &sim->forks[0]; // for the last philosopher
        pthread_mutex_init(&sim->forks[i], NULL);
        //pthread_mutex_init(&g_check_death[i], NULL);
        i++;
    }
}
#include "../includes/philo_two.h"

void init_philo(t_sim *sim)
{
    int i;

    i = 0;
    sim->philos = malloc(sizeof(t_philo) * sim->philo_num);
    sim->forks = malloc(sizeof(sem_t) * sim->philo_num);
    while (i < sim->philo_num)
    {
        sim->philos[i].philo_id = i + 1;
        sim->philos[i].time_to_eat = sim->time_to_eat;
        sim->philos[i].philo_num = sim->philo_num;
        sim->philos[i].time_to_die = sim->time_to_die;
        sim->philos[i].time_to_sleep = sim->time_to_sleep;
        sim->philos[i].num_must_eat = sim->num_must_eat;
        sim->philos[i].meal_count = 0;
        sim->philos[i].is_dead = 1;
        sim->philos[i].left_fork = &sim->forks[i];
        if (i < sim->philo_num - 1)
            sim->philos[i].right_fork = &sim->forks[i + 1];
        else
            sim->philos[i].right_fork = &sim->forks[0]; // for the last philosopher
        // if (!(sim->forks[i] = sem_open(SEM_FORKS, O_CREAT, 0666, 1)))
        // {
        //     print_error("Error: failed to init forks semaphore\n");
        //     // return(FAIL);
        // }
        i++;
    }
}
#include "../includes/philo_one.h"

void init_mutexes_arrs(t_sim *sim)
{
	int				i;

	sim->forks = malloc(sizeof(pthread_mutex_t) * sim->philo_num);
    print_status = malloc(sizeof(pthread_mutex_t) * sim->philo_num); 

	i = 0;
	while (i < sim->philo_num)
	{
		pthread_mutex_init(&sim->forks[i], NULL);
        pthread_mutex_init(&print_status[i], NULL);
		i++;
	}
}
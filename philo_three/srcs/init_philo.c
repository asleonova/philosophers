#include "../includes/philo_three.h"

void init_philo(t_sim *sim)
{
	int i;

	i = 0;
	sim->philos = malloc(sizeof(t_philo) * sim->philo_num);
	while (i < sim->philo_num)
	{
		sim->philos[i].philo_id = i + 1;
		sim->philos[i].time_to_eat = sim->time_to_eat;
		sim->philos[i].philo_num = sim->philo_num;
		sim->philos[i].time_to_die = sim->time_to_die;
		sim->philos[i].time_to_sleep = sim->time_to_sleep;
		sim->philos[i].num_must_eat = sim->num_must_eat;
		sim->philos[i].meal_count = 0;
		sim->philos[i].is_dead = 0;
		sim->philos[i].g_check_death = sim->g_check_death;
		sim->philos[i].processes = -1;
		i++;
	}
}
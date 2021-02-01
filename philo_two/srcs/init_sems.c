#include "../includes/philo_two.h"

int						init_sems(t_sim *sim)
{
	sem_unlink(SEM_STATUS);
	sem_unlink(SEM_DEATH);
    sem_unlink(SEM_FORKS);
	sem_unlink(SEM_GRAB_FORKS);
	// int i = 0;
	// g_check_death = malloc(sizeof(sem_t *) * (sim->philo_num));
	if (!(g_print_status = sem_open(SEM_STATUS, O_CREAT, 0666, 1)))
		return (print_error("Error: failed to create a thread\n"));
	if (!(g_check_death = sem_open(SEM_DEATH, O_CREAT, 0666, 1)))
		return (print_error("Error: failed to create a thread\n"));
	if (!(g_forks = sem_open(SEM_FORKS, O_CREAT, 0666, sim->philo_num)))
		return (print_error("Error: failed to create a thread\n"));
	// if (!(g_grab_forks = sem_open(SEM_FORKS, O_CREAT, 0666, 1)))
	// 	return (print_error("Error: failed to create a thread\n"));

	// while (i < sim->philo_num)
	// {
	// 	g_check_death[i] = sem_open(SEM_DEATH, O_CREAT, 0666, 1);	
	// 	i++;
	// }
    // if (!(sim->forks = sem_open(SEM_FORKS, O_CREAT, 0666, sim->philo_num)))
	// 	return (print_error("Error: failed to create a thread\n"));

	return (SUCCESS);
}

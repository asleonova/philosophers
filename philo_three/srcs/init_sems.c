#include "../includes/philo_three.h"

int						init_sems(t_sim *sim)
{
	sem_unlink(SEM_STATUS);
	sem_unlink(SEM_DEATH);
	sem_unlink(SEM_FORKS);
	if (!(g_print_status = sem_open(SEM_STATUS, O_CREAT, 0666, 1)))
		return (print_error("Error: failed to create a semaphore\n"));
	if (!(sim->g_check_death = sem_open(SEM_DEATH, O_CREAT, 0666, 1)))
		return (print_error("Error: failed to create a semaphore\n"));
	if (!(g_forks = sem_open(SEM_FORKS, O_CREAT, 0666, sim->philo_num)))
		return (print_error("Error: failed to create a semaphore\n"));
	return (SUCCESS);
}

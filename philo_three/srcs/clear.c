#include "../includes/philo_three.h"

void    clean_and_destroy(t_sim *sim)
{
    int i;
    i = 0;
    sem_post(g_print_status);
    sem_close(g_check_death);
    while (i < sim->philo_num)
    {
        sem_post(g_forks);
        i++;
        }
        sem_close(g_forks);
}


void	kill_processes(int num, t_sim *sim)
{
	int i;

	i = 0;
	while (i < num)
	{
		kill(sim->philos[i].processes, SIGTERM);
		i++;
	}
}
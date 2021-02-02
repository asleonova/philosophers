#include "../includes/philo_three.h"


void has_taken_a_fork(t_philo *philo)
{
	sem_wait(g_forks);
	print_status("has taken a fork", philo, 0);
	sem_wait(g_forks);
	print_status("has taken a fork", philo, 0);
}

void is_eating(t_philo *philo)
{
	sem_wait(g_check_death);
	philo->start_eating = get_time_val();
	sem_post(g_check_death);
	print_status("is eating", philo, 0);
	ft_sleep(philo->time_to_eat);
	philo->meal_count += 1;
	sem_post(g_forks);
	sem_post(g_forks);

}

void *philosophers(void *philos)
{
	t_philo *philo;
	
	int i = 0;
	philo = (t_philo*)philos;
	while (!is_dead) // while philosophers are alive and not full
	{
		if (!i) // needs to track the starving time in the first loop
		{
			sem_wait(g_check_death);
			philo->start_eating = get_time_val();
			sem_post(g_check_death);
			i++;
		}
		has_taken_a_fork(philo);
		is_eating(philo);
		if (is_dead == 1)
			break ;
		print_status("is sleeping", philo, 0);
		if (is_dead == 1)
			break ;
		ft_sleep(philo->time_to_sleep);
		print_status("is thinking", philo, 0);
   	}
	return(NULL);
}
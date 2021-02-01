#include "../includes/philo_two.h"

void	ft_sleep(int time)
{
	long start_time;
	start_time = get_time_val();
	while (get_time_val() - start_time < time)
		 usleep(1);
}

int         start_philo_thread(t_sim *sim)
{
    int i;
    pthread_t t[sim->philo_num];
    int res;

    i = 0;
    while (i < sim->philo_num)
    {
        res = pthread_create(&t[i], NULL, philosophers, (void*)&sim->philos[i]);
        usleep(50);
        if (res != 0)
            return(print_error("Error: failed to create a thread\n"));
        i++;
    }
    return (SUCCESS);
}

void has_taken_a_fork(t_philo *philo)
{
	//sem_wait(g_grab_forks);
	sem_wait(g_forks);
	print_status("has taken a fork", philo, 0);
	sem_wait(g_forks);
	print_status("has taken a fork", philo, 0);
	//sem_post(g_grab_forks);
}

void is_eating(t_philo *philo)
{
	// int id = philo->philo_id;
	
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
	// int id = philo->philo_id;
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
	//	sem_wait(g_check_death);
		if (is_dead == 1)
			break ;
		print_status("is sleeping", philo, 0);
		if (is_dead == 1)
			break ;
		ft_sleep(philo->time_to_sleep);
		print_status("is thinking", philo, 0);
		//sem_post(g_check_death);
		//i++;
   	}
	return(NULL);
}
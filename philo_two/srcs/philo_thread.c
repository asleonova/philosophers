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
        {
            print_error("Error: failed to create a thread\n");
            return (FAIL);
        }
        i++;
    }
    return (SUCCESS);
}

void has_taken_a_fork(t_philo *philo)
{
	sem_wait(g_forks);
	print_status("has taken a fork", philo, 0);
	sem_wait(g_forks);
	print_status("has taken a fork", philo, 0);
}

void is_eating(t_philo *philo)
{
	//sem_wait(g_check_death);
	philo->start_eating = get_time_val();
	print_status("is eating", philo, 0);
	//sem_post(g_check_death);
	ft_sleep(philo->time_to_eat);
	sem_post(g_forks);
	sem_post(g_forks);
	philo->meal_count += 1;
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
			philo->start_eating = get_time_val();
			i++;
		}
		has_taken_a_fork(philo);
		is_eating(philo);
		sem_wait(g_check_death);
		print_status("is sleeping", philo, 0);
		ft_sleep(philo->time_to_sleep);
		print_status("is thinking", philo, 0);
		sem_post(g_check_death);
   }
	return(NULL);
}
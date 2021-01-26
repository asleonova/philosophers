#include "../includes/philo_one.h"

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
	pthread_mutex_lock(philo->left_fork);
	print_status("has taken a fork", philo);
	pthread_mutex_lock(philo->right_fork);
	print_status("has taken a fork", philo);
}

void is_eating(t_philo *philo)
{
	philo->wait_fork = get_time_val();
	print_status("is eating", philo);
	usleep(20);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);	
}

void *philosophers(void *philos)
{
    t_philo *philo;

    philo = (t_philo*)philos;
    while (1)
    {
		print_status("is thinking", philo);
		has_taken_a_fork(philo);
		is_eating(philo);
		print_status("is sleeping", philo);
		usleep(20);
   }
	return(NULL);
}

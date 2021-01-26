#include "../includes/philo_one.h"

// void	ft_sleep(t_philo *philo)
// {
// 	while (get_time_val() - philo->start_sleeping < philo->time_to_sleep)
// 		usleep(1);
// }

// void	ft_eat(t_philo *philo)
// {
// 	while (get_time_val() - philo->start_sleeping < philo->time_to_sleep)
// 		usleep(1);
// }

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
	pthread_mutex_lock(philo->left_fork);
	print_status("has taken a fork", philo);
	pthread_mutex_lock(philo->right_fork);
	print_status("has taken a fork", philo);
}

void is_eating(t_philo *philo)
{
	//philo->start_eating = get_time_val();
	printf("ADSAFDFFDFDS: %ld\n", philo->start_eating);
	print_status("is eating", philo);
	ft_sleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);	
}

void *philosophers(void *philos)
{
    t_philo *philo;
	

    philo = (t_philo*)philos;
    while (philo->is_dead)
    {
	   	philo->start_eating = get_time_val();	
		has_taken_a_fork(philo);
		is_eating(philo);
		print_status("is sleeping", philo);
		// philo->start_sleeping = get_time_val();
		ft_sleep(philo->time_to_sleep);
		print_status("is thinking", philo);
   }
	return(NULL);
}




// void	wait_n_miliseconds(long miliseconds)
// {
// 	long	time_to;
// 	long	current;

// 	current = get_abs_time_stamp();
// 	time_to = current + miliseconds;
// 	usleep(miliseconds * 1000 - 7000);
// 	while (1)
// 	{
// 		current = get_abs_time_stamp();
// 		if (current >= time_to)
// 			break ;
// 		else
// 			usleep(100);
// 	}
// }

// ft_sleep(info->time_to_sleep);

// void	ft_sleep(int milis)
// {
// 	long start_time;

// 	start_time = get_time();
// 	while (get_time() - start_time < milis)
// 	{
// 		usleep(500);
// 	}
// }

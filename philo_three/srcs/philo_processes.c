#include "../includes/philo_three.h"

void ft_sleep(int time)
{
	long start_time;
	start_time = get_time_val();
	while (get_time_val() - start_time < time)
		usleep(1);
}

void main_process(t_sim *sim)
{
	int i;
	int count;
	int status;

	count = 0;
	i = 0;
	while (i < sim->philo_num)
	{
		waitpid(-1, &status, 0); // -1 meaning wait for any child process whose process group ID is equal to the absolute value of pid.
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			waitpid(-1, &status, WUNTRACED);
		count += WEXITSTATUS(status);
		if (count == 0)				  // если процесс завершился, т.е. философ умер, то выходим
			return;
		else
			i += 1;
	}
	return; // выходим в любом случае, когда прошлись по всем философам
}

int is_full(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->philo_num)
	{
		if (philo[i].meal_count < philo->num_must_eat)
			return (0);
		i++;
	}
	return (1);
}

void		*monitoring(void *monitor)
{
	t_philo	*philo;
	
	philo = (t_philo*)monitor;
	while (1)
	{
		usleep(1000);
		sem_wait(philo->g_check_death);
		if (philo->num_must_eat != 0 && philo->meal_count >= philo->num_must_eat)
		{
			sem_post(philo->g_check_death);
			sem_wait(g_print_status);
			printf("All philosophers are full now. Game over!\n");
			exit (0);
		}
		if (get_time_val() - philo->start_eating > philo->time_to_die)
		{
			print_status("died\n", philo, 1);
			sem_post(philo->g_check_death);
			exit(0);
		}
		sem_post(philo->g_check_death);
	}
	return (NULL);
}

int philo_process(t_sim *sim)
{
	int i;
	pid_t pid;
	pthread_t monitor;

	i = 0;
	while (i < sim->philo_num)
	{
		pid = fork();
		if (pid == 0)
		{
			pthread_create(&monitor, NULL, monitoring, (void *)&sim->philos[i]);
			philosophers((void *)&sim->philos[i]);
		}
		if (pid == -1)
		{
			write(2, "error, fatal\n", 13);
			exit(1);
		}
		sim->philos[i].processes = pid;
		i++;
		usleep(50);
	}
	return (SUCCESS);
}

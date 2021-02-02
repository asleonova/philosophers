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
	i = -1;
	//sleep(10);
	while (i < sim->philo_num)
	{
		waitpid(-1, &status, 0); // -1 meaning wait for any child process whose process group ID is equal to the absolute value of pid.
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			waitpid(-1, &status, WUNTRACED);
		count += WEXITSTATUS(status); // посмотреть, какие могут быть статусы!!!!
		if (count == 0)				  // если процесс завершился, т.е. философ умер, то выходим
			return;
		else
			i += 1;
	}
	return; // выходим в любом случае, когда прошлись по всем философам
}

int is_full(t_sim *sim)
{
	int i;

	i = 0;
	while (i < sim->philo_num)
	{
		if (sim->philos[i].meal_count < sim->num_must_eat)
			return (0);
		i++;
	}
	return (1);
}

int check_if_over(t_sim *sim)
{
	int i;
	while (!is_dead)
	{
		i = 0;
		while (i < sim->philo_num)
		{
			sem_wait(g_check_death);
			if (sim->num_must_eat != 0 && is_full(sim))
			{
				is_dead = 2;
				sem_post(g_check_death);
				//exit(1);
				return (0);
			}
			else if (get_time_val() - sim->philos[i].start_eating > sim->philos[i].time_to_die)
			{
				print_status("died\n", &sim->philos[i], 1);
				is_dead = 1;
				sem_post(g_check_death);
				exit(0);
			}
			sem_post(g_check_death);
			i++;
		}
	}
	return (1);
}

void *monitoring(void *monitor)
{
	t_sim check_death;

	check_death = *(t_sim *)monitor;

	while (1) //while 1
	{
		usleep(2000);
		if (!check_if_over(&check_death))
			break;
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
		if (pid < 0)
		{
			write(2, "error, fatal\n", 13);
			exit(1);
		}
		sim->philos[i].processes = pid;
		// мб тут запомнить все значения pid и туда записать
		usleep(50);
		i++;
	}
	return (SUCCESS);
}

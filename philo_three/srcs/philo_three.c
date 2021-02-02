#include "../includes/philo_three.h"

// int is_full(t_sim *sim)
// {
// 	int i;
	
// 	i = 0;
// 	while (i < sim->philo_num)
// 	{
// 		if (sim->philos[i].meal_count < sim->num_must_eat)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// int check_if_over(t_sim *sim)
// {
// 	int i;
// 	while (!is_dead)
// 	{
// 	   i = 0;
// 		while (i < sim->philo_num)
// 		{
// 			sem_wait(g_check_death);
// 			if (sim->num_must_eat != 0 && is_full(sim))
// 			{
// 				is_dead = 2;
// 				sem_post(g_check_death);
// 				return (0);
// 			}         
// 			else if (get_time_val() - sim->philos[i].start_eating > sim->philos[i].time_to_die)
// 			{
// 				print_status("died\n", &sim->philos[i], 1);
// 				is_dead = 1;
// 				sem_post(g_check_death);
// 				return (0);
// 			}
// 		   sem_post(g_check_death);
// 		   i++;
// 		}
// 	}
// 	return (1);
// }

int main(int ac, char **av)
{
	t_sim sim;

	is_dead = 0;
	g_start_time = get_time_val();
	if (parse_params(&sim, ac, av) == FAIL)
		return (FAIL);
	init_philo(&sim);
	init_sems(&sim);
	philo_process(&sim);
	main_process(&sim);
	kill_processes(sim.philo_num, &sim);
	clean_and_destroy(&sim);
	if (is_dead == 2)
		printf("All philosophers are full now. Game over!\n");
	//exit (0);
	return (0);
}

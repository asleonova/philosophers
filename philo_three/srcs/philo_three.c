#include "../includes/philo_three.h"

int main(int ac, char **av)
{
	t_sim sim;

	g_start_time = get_time_val();
	if (parse_params(&sim, ac, av) == FAIL)
		return (FAIL);
	init_philo(&sim);
	init_sems(&sim);
	philo_process(&sim);
	main_process(&sim);
	kill_processes(sim.philo_num, &sim);
	clean_and_destroy(&sim);
	return (0);
}

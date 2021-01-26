#include "../includes/philo_one.h"

int check_if_dead(t_sim *sim)
{
    int i;

    while (sim->is_dead)
    {
        i = 0;
       // int time = get_time_val();
        while (i < sim->philo_num)
        {
           pthread_mutex_lock(&g_check_death);
            if (get_time_val() - sim->philos[i].start_eating > sim->philos[i].time_to_die)
            {
                print_status("died\n", &sim->philos[i]);
                sim->is_dead = 0;
                return (0);
            }
           pthread_mutex_unlock(&g_check_death);
            i++;
        }
    }
    return (1);
}

// monitor = value;
// now = get_time();
// while (1)
// {
// 	pthread_mutex_lock(monitor->protectors[monitor->number]);
// 	now = get_time();
// 	pthread_mutex_unlock(monitor->protectors[monitor->number]);
// 	diff = now - monitor->lastmeal[monitor->number];
// 	if (diff > monitor->time_to_die || *(monitor->death_flag) != -1)
// 	{
// 		proclaim_death(monitor);
// 		break ;
// 	}
// 	if (monitor->eat_target != -1 && all_done(monitor) == 1)
// 	{
// 		*(monitor->death_flag) = 42;
// 		return (NULL);
// 	}
// 	usleep(MONITORING_DELAY);
// }
// return (NULL);

// static	int	check_if_daed_and_print_status(t_sim_model *m, t_philo *p)
// {
// 	long	current_time;

// 	current_time = get_reletive_time_stamp(p);
// 	if (current_time - p->meal_time > m->time_to_die)
// 	{
// 		print_status(p, current_time, "died", 1);
// 		pthread_mutex_unlock(p->check_dead_m);
// 		return (STOP_DEAD);
// 	}
// 	return (CONTINUE);
// }

int main(int ac, char **av)
{
    t_sim sim;

    // g_print_status = malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(&g_print_status, NULL);
    pthread_mutex_init(&g_check_death, NULL);
    g_start_time = get_time_val();
    if (parse_params(&sim, ac, av) == FAIL)
        return (FAIL);
    init_philo(&sim);
    int res;
    res = start_philo_thread(&sim);
    sim.is_dead = 1;
    while (sim.philos->is_dead) //while 1
    {
        usleep(1000);
        if (!check_if_dead(&sim))
            break;
    }
    return (res);
}

// void	wait_till_dead_or_fed(t_sim_model *mdl)
// {
// 	int		res;

// 	while (1)
// 	{
// 		usleep(1000);
// 		if ((res = check_sim_end_and_print_status(mdl)) == STOP_DEAD)
// 			break ;
// 		else if (res == STOP_FED)
// 			break ;
// 	}
// }

// int			check_sim_end_and_print_status(t_sim_model *mdl)
// {
// 	int		i;
// 	t_philo	*p;
// 	int		all_fed;

// 	all_fed = 1;
// 	i = 1;
// 	while (i <= mdl->philos_count && (p = mdl->philos + i))
// 	{
// 		pthread_mutex_lock(p->check_dead_m);
// 		if (check_if_daed_and_print_status(mdl, p) == STOP_DEAD)
// 			return (STOP_DEAD);
// 		all_fed *= is_fed(mdl, p);
// 		pthread_mutex_unlock(p->check_dead_m);
// 		i++;
// 	}
// 	if (mdl->num_must_eat != -2 && all_fed == 1)
// 	{
// 		print_message("All philosophers are fed\n", 1, mdl);
// 		return (STOP_FED);
// 	}
// 	return (CONTINUE);
// }

// static	int	is_fed(t_sim_model *m, t_philo *p)
// {
// 	if (m->num_must_eat != -2 && p->num_ate < m->num_must_eat)
// 		return (0);
// 	return (1);
// }

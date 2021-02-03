void	*monitoring_thread(void *value)
{
	t_briefcase	*monitor;
	long		now;
	long		diff;

	monitor = value;
	now = get_time();
	while (1)
	{
		sem_wait(monitor->protectors[monitor->number]);
		now = get_time();
		sem_post(monitor->protectors[monitor->number]);
		diff = now - monitor->last_meal;
		if (diff > monitor->time_to_die)
		{
			monitor->death_flag = 0;
			sem_wait(monitor->finish);
			sem_wait(monitor->print);
			rogue_print_state("died", monitor->number + 1);
			exit(0);
		}
		usleep(MONITORING_DELAY);
	}
}

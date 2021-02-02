#include "../includes/philo_three.h"

static int	ft_atoi(char *str)
{
	int	res;
	int	i;
	int error;

	i = 0;
	res = 0;
	error = (ft_strlen(str));

	if (error > 3)
		return(-1);
	if (str[0] == '\0')
		return (-1);
	if (str[0] == '0')
		str++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if(str[i] != '\0')
		return(-1);
	return (res);
}


static int check_if_num_positive(t_sim *sim)
{
	if (sim->philo_num < 0 || sim->time_to_die < 0 || sim->time_to_eat < 0 
		|| sim->time_to_sleep < 0 || sim->num_must_eat < 0)
		return(FAIL);
	return(SUCCESS);    
}

int parse_params(t_sim *sim, int ac, char **av)
{
	int res;
	
	res = 0;
	if (ac == 5 || ac == 6)
	{
		sim->philo_num = ft_atoi(av[1]);
		sim->time_to_die = ft_atoi(av[2]);
		sim->time_to_eat = ft_atoi(av[3]);
		sim->time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			sim->num_must_eat = ft_atoi(av[5]);
		else
			sim->num_must_eat = 0; // this param is optional. so 0 means it's uninialised;
		if (check_if_num_positive(sim) == FAIL)
			res = print_error("Error: options must contain only positive number (in the range of 0 to 1000)\n");
		if (sim->philo_num < 2)
			res = print_error("Error: the min num of philosophers must be 2\n");
	}
	else 
		res = print_error("Bad number of arguments\n");
	return (res);
}
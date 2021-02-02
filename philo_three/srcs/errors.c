#include "../includes/philo_three.h"

int print_error(char *error)
{
	write(2, error, ft_strlen(error));
	return(FAIL);
}
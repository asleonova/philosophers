#include <stdio.h>

static	long	atoi_unsigned(const char *str)
{
	long	result;

	if (*str == '\0')
		return (-1);
	result = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		if (result < 0)
			return (-1);
		str++;
	}
	if (*str != '\0')
		return (-1);
	return (result);
}
int	ft_atoi(char *str)
{
	int	res;
	int	i;
	int error;

	i = 0;
	res = 0;
	error = (ft_strlen(str));

	if (error > 3)
		return(-2);
	if (str[0] == '\0')
		return (-1);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if(str[i] != '\0')
		return(-1);
	return (res);
}

int main()
{
    printf("-234234: %ld\n", ft_atoi("-234234"));
    printf("23423411432: %ld\n", ft_atoi("23423411432"));
    printf("aaaa: %ld\n", ft_atoi("aaaa"));
    printf("1231dda: %ld\n", ft_atoi("1231dda"));
     
    return (0);
}
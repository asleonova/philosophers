#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

# define SUCCESS 0
# define FAIL 1
/*
    philo_num - number of  philosophers and also number of forks

    time_to_die - in miliseconds, if a philosopher doesn't start eating,
    'time_to_die' milliseconds after starting his last meal or the beginning 
    of the simulation, it dies.

    time_to_eat - in miliseconds, is the time it takes for a philosopher to eat.
    during that time he will keep 2 forks. 

    time_to_sleep - in miliseconds, time the philosopher will spend sleeping

    num_must_eat (optional), if all philosophers eat at least 'num_must_eat' times, 
    the simulation will stop. If not specified, the simulation will stop only at the death
    of a philosopher.

    example of parameters to the program: 
    ./philo_ont 5 800 200 200 3

*/
pthread_mutex_t *print_status;
int start_time;

typedef struct s_philo
{
    int philo_id;
    int time_to_eat;
    int time_to_die;
    int time_to_sleep;
    int num_must_eat;
    int is_dead;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    

}               t_philo;

typedef struct s_sim
{
    int philo_num;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int num_must_eat;
    pthread_mutex_t *forks;
    t_philo *philos;

}               t_sim;

int ft_strlen(char *str);
int print_error(char *error);
int parse_params(t_sim *sim, int ac, char **av);
void init_philo(t_sim *sim);
void init_mutexes_arrs(t_sim *sim);
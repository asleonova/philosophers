#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>
# include <semaphore.h>
# include <fcntl.h>

# define SEM_STATUS "/status"
# define SEM_DEATH "/death"
# define SEM_FORKS "/forks"

# define SUCCESS 0
# define FAIL 1
# define EXITED 0
# define IN_PROCESS 
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
	./philo_one 5 800 200 200 3

*/
sem_t *g_print_status;
//sem_t *g_check_death;
sem_t *g_forks;

long g_start_time;
int is_dead;

typedef struct s_philo
{
	int philo_num;
	int philo_id;
	int time_to_eat;
	int time_to_die;
	int time_to_sleep;
	int num_must_eat;
	int is_dead;
	int meal_count;
	long start_eating;
	pid_t processes;
	sem_t *g_check_death;
}               t_philo;

typedef struct s_sim
{
	int philo_num;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int num_must_eat;
	int is_dead;
	sem_t *g_check_death;
	t_philo *philos;

}               t_sim;

int			ft_strlen(char *str);
int			print_error(char *error);
int			parse_params(t_sim *sim, int ac, char **av);
void		init_philo(t_sim *sim);
long		get_time_val(void);
int			philo_process(t_sim *sim);
void		*philosophers(void *philos);
void 		print_status(char *status, t_philo *philo, int game_over);
void		main_process(t_sim *sim);
void    	clean_and_destroy(t_sim *sim);
int			init_sems(t_sim *sim);
void	kill_processes(int num, t_sim *sim);
void		ft_sleep(int time);
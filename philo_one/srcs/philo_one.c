#include "../includes/philo_one.h"

int main(int ac, char **av)
{
    t_sim sim;

    if (parse_params(&sim, ac, av) == FAIL)
        return (FAIL);
    init_mutexes_arrs(&sim);
    init_philo(&sim);
    
    printf("philo_num: %d\n", sim.philo_num);
    printf("time_to_die: %d\n", sim.time_to_die);
    printf("time_to_eat: %d\n", sim.time_to_eat);
    printf("time_to_eat: %d\n", sim.time_to_sleep);
    printf("must eat: %d\n", sim.num_must_eat);
    printf("*****************************\n\n\n");
   
    int i = 0;

    while (i < sim.philo_num)
    {
        printf("id: %d\n", sim.philos[i].philo_id);
        printf("time_to_eat: %d\n",sim.philos[i].time_to_eat);
        printf("time_to_die: %d\n", sim.philos[i].time_to_die); 
        printf("time_to_sleep: %d\n",sim.philos[i].time_to_sleep);
        printf("must_eat: %d\n", sim.philos[i].num_must_eat);
        printf("is_dead: %d\n", sim.philos[i].is_dead);
      //  printf("left_fork: %d\n",sim.philos[i].left_fork);
       // printf("right_fork: %d\n\n",sim.philos[i].right_fork);
        i++;
    }

   
    return(0);
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>
#include <fcntl.h>
#include <pthread.h>

#define THREAD_NUM 4

#define sem_name "/semaphore"
sem_t *semaphore;

void *routine(void* args)
{
    sem_wait(semaphore);
    //usleep(1);
    printf("Hello from thread %d\n", *(int*)args);
    sem_post(semaphore);
    free(args);
    return (NULL);
}

int main(int ac, char **av)
{
    pthread_t th[THREAD_NUM];
    sem_unlink(sem_name);
    semaphore = sem_open(sem_name, O_CREAT, 0666, 1);
    //sem_init(&semaphore, 0, 1);
    int i;
    for (i = 0; i < THREAD_NUM; i++)
    {
        int *a = malloc(sizeof(int));
        *a = i;
        if (pthread_create(&th[i], NULL, routine, a) != 0) 
            perror("Failed to create thread");
    //    usleep(1);
    }
    sleep(5);
    sem_close(semaphore);
    sem_unlink(sem_name);
    return(0);
}
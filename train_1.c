#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void* myturn(void *arg)
{
    int *p = (int *)malloc(sizeof(int));
    *p = 5;
    for (int i = 0; i < 5; i++)
    {
        sleep(1);
        printf("My turn %d\n", *p);
        (*p)++;
    }
    return p;
}

void yourturn()
{
    for(int i = 0; i < 3; i++)
    {
        sleep(2);
        printf("Your turn\n");
    }
}
int main (void)
{
    pthread_t new_thread;
    int *res;

    pthread_create(&new_thread, NULL, myturn, NULL);
    //myturn(); 
    yourturn();
    pthread_join(new_thread, (void *)&res);
    printf("thread's done: res=%d\n", *res);
}
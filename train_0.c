#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *myturn(void *arg)
{
    for (int i = 0; i < 5; i++)
    {
        sleep(1);
        printf("My turn!, %d\n", i);
    }
    return NULL;
}

void yourturn()
{
    for (int i = 0; i < 3; i++)
    {
        sleep(2);
        printf("Your turn!, %d\n", i);
    }
}

int main()
{
    pthread_t t;

    //pthread_create(&t, NULL, myturn, NULL);
    yourturn();
    //pthread_join(t, NULL);
    return(0);
}
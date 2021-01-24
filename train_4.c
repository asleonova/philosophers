#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define BIG 10000000
int count = 0;

void *count_to_big(void *arg)
{
    for (int i = 0; i < BIG; i++)
    {
       count++;
    }
    return (NULL);
}

int main()
{
    pthread_t t;

    pthread_create(&t, NULL, count_to_big, NULL);
    count_to_big(NULL);
    pthread_join(t, NULL);
    printf("Done, counter = %d\n", count);
}
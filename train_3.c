#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define BIG 10000000
int count = 0;

void count_to_big()
{
    for (int i = 0; i < BIG; i++)
    {
        count++;
    }
}

int main()
{
    count_to_big();
    count_to_big();
    printf("Done, counter = %d\n", count);
}
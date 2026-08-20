#include <stdio.h>
#include <pthread.h>

int count = 0;

pthread_mutex_t mutex;

void *increment(void *arg)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&mutex);

        count++;
        printf("Thread 1: count = %d\n", count);

        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

void *decrement(void *arg)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&mutex);

        count--;
        printf("Thread 2: count = %d\n", count);

        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main()
{
    pthread_t thread1, thread2;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&thread1, NULL, increment, NULL);
    pthread_create(&thread2, NULL, decrement, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex);

    printf("\nFinal count = %d\n", count);

    return 0;
}
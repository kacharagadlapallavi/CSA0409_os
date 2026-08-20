#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int data = 0;
int read_count = 0;

sem_t mutex;
sem_t write_lock;

void *reader(void *arg)
{
    int id = *(int *)arg;

    sem_wait(&mutex);

    read_count++;

    if (read_count == 1)
        sem_wait(&write_lock);

    sem_post(&mutex);

    printf("Reader %d is reading data = %d\n", id, data);
    sleep(1);

    sem_wait(&mutex);

    read_count--;

    if (read_count == 0)
        sem_post(&write_lock);

    sem_post(&mutex);

    return NULL;
}

void *writer(void *arg)
{
    int id = *(int *)arg;

    sem_wait(&write_lock);

    data++;
    printf("Writer %d is writing data = %d\n", id, data);
    sleep(1);

    sem_post(&write_lock);

    return NULL;
}

int main()
{
    pthread_t readers[3], writers[2];

    int reader_id[3] = {1, 2, 3};
    int writer_id[2] = {1, 2};

    sem_init(&mutex, 0, 1);
    sem_init(&write_lock, 0, 1);

    pthread_create(&readers[0], NULL, reader, &reader_id[0]);
    pthread_create(&readers[1], NULL, reader, &reader_id[1]);

    pthread_create(&writers[0], NULL, writer, &writer_id[0]);

    pthread_create(&readers[2], NULL, reader, &reader_id[2]);

    pthread_create(&writers[1], NULL, writer, &writer_id[1]);

    for (int i = 0; i < 3; i++)
        pthread_join(readers[i], NULL);

    for (int i = 0; i < 2; i++)
        pthread_join(writers[i], NULL);

    sem_destroy(&mutex);
    sem_destroy(&write_lock);

    return 0;
}
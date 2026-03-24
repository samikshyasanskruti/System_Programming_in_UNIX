#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

int buffer = 0;
sem_t empty;
sem_t full;     // two semaphore 

void* producer(void* arg) {
    for (int i = 1; i <= 5; i++) {
        sem_wait(&empty);        
        buffer = i;
        printf("producer produced %d\n", i);
        sem_post(&full);        

        sleep(1);
    }
    return NULL;
}

void* consumer(void* arg) {
    for (int i = 1; i <= 5; i++) {

        sem_wait(&full);        // lock
        printf("consumer consumed %d\n", buffer);
        buffer = i;
        sem_post(&empty);        // unlock

        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t p, c;

    sem_init(&empty, 0, 1);   
    sem_init(&full, 0, 1);   

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    sem_destroy(&empty);
    sem_destroy(&empty);
    return 0;
}


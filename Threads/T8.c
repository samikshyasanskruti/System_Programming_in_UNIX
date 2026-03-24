#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

int buffer = 0;
sem_t sem;     // only one semaphore 

void* producer(void* arg) {
    for (int i = 1; i <= 5; i++) {
        sem_wait(&sem);        
        buffer = i;
        printf("producer produced %d\n", i);
        sem_post(&sem);        

        sleep(1);
    }
    return NULL;
}

void* consumer(void* arg) {
    for (int i = 1; i <= 5; i++) {

        sem_wait(&sem);        // lock
        printf("consumer consumed %d\n", buffer);
        buffer = i;
        sem_post(&sem);        // unlock

        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t p, c;

    sem_init(&sem, 0, 1);   // binary semaphore (mutex)

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    sem_destroy(&sem);

    return 0;
}


//Barrier Program
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_barrier_t barrier;

void* worker(void* arg) {
    printf("[Thread %lu] Phase 1 done\n", (unsigned long)pthread_self());
    pthread_barrier_wait(&barrier);
    printf("[Thread %lu] Phase 2 done\n", (unsigned long)pthread_self());
    pthread_barrier_wait(&barrier);
    printf("[Thread %lu] Phase 3 done\n", (unsigned long)pthread_self());
    return NULL;
}

int main() {
    pthread_t t[3];
    pthread_barrier_init(&barrier, NULL, 3);

    for (int i = 0; i < 3; i++) pthread_create(&t[i], NULL, worker, NULL);
    for (int i = 0; i < 3; i++) pthread_join(t[i], NULL);

    pthread_barrier_destroy(&barrier);
    return 0;
}

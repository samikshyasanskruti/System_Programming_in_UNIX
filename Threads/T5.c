#include<stdio.h>
#include<pthread.h>

long counter=0;
pthread_mutex_t lock;
void*increment(void* arg){
    for(int i=0;i<1000000;i++){
       pthread_mutex_lock(&lock);
       counter++; //race here
       pthread_mutex_unlock(&lock);
    }
    return NULL;
}
int main(){
    pthread_t t1,t2,t3,t4,t5;
    pthread_mutex_init(&lock,NULL);
    pthread_create(&t1,NULL,increment,NULL);
    pthread_create(&t2,NULL,increment,NULL);
    pthread_create(&t3,NULL,increment,NULL);
    pthread_create(&t4,NULL,increment,NULL);
    pthread_create(&t5,NULL,increment,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    pthread_join(t4,NULL);
    pthread_join(t5,NULL);
                
    printf("Final counter=%ld\n",counter);
    pthread_mutex_destroy(&lock);
    return 0;
}

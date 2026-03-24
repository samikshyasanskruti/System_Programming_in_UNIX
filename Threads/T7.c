#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
int buffer=0;
pthread_mutex_t lock;
pthread_cond_t cond;
void* producer(void*arg){
      for(int i=1;i<=5;i++){
           pthread_mutex_lock(&lock);
           while(buffer!=0)
                 pthread_cond_wait(&cond,&lock);
           buffer=i;
           printf("producer produced %d\n",i);
           pthread_cond_signal(&cond);
           pthread_mutex_unlock(&lock);
           sleep(1);
       }
       return NULL;
}
void* consumer(void*arg){
      for(int i=1;i<=5;i++){
           pthread_mutex_lock(&lock);
           while(buffer==0)
                 pthread_cond_wait(&cond,&lock);
           printf("consumer consumed %d\n",buffer);
           buffer=0;
           pthread_cond_signal(&cond);
           pthread_mutex_unlock(&lock);
           sleep(2);
       }
       return NULL;
 }
int main(){
    pthread_t p,c;
    pthread_mutex_init(&lock,NULL);
    pthread_cond_init(&cond,NULL);
    
    pthread_create(&p,NULL,producer,NULL);
    pthread_create(&p,NULL,consumer,NULL);
    
    pthread_join(p,NULL);
    pthread_join(c,NULL);
    
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);
    
    return 0;
    }
    
               
      


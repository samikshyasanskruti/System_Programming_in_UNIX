#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void* run(void* arg){
      printf("[Thread] Running:pthread_self()+%lu\n",(unsigned long)pthread_self());
      return NULL;
}
int main(){
    pthread_t tid;
    if(pthread_create(&tid,NULL,run,NULL)!=0)
    {
       perror("pthread_create");
       return 1;
    }
    pthread_join(tid,NULL);
    printf("[Main] Thread joined.Exiting\n");
    return 0;
}

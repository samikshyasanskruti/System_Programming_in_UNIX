#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void* run(void* arg){
      int v=*(int*)arg;
      printf("[Thread] Received value=%d\n",v);
      return NULL;
}
int main(){
    pthread_t tid;
    int a=10;
    int b=20;
    int val=a+b;
    pthread_create(&tid,NULL,run,&val);
    pthread_join(tid,NULL);
    return 0;
}

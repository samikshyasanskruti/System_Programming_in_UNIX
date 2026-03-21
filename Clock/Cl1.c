#include<unistd.h>
#include<time.h>
#include<stdio.h>
#include<sys/time.h>
int main(){
    struct timespec ts1,ts2;
    clock_t c1=clock();
    clock_gettime(CLOCK_MONOTONIC,&ts1);
    sleep(1);
    for(volatile long i=0;i<1e8;i++);
    clock_t c2=clock();
    clock_gettime(CLOCK_MONOTONIC,&ts2);
    double real=(ts2.tv_sec-ts1.tv_sec)+
                (ts2.tv_nsec-ts1.tv_nsec)/1e9;
    double cpu=(double)(c2-c1)/CLOCKS_PER_SEC;
    printf("Real time:%.6f s\n",real);
    printf("CPU time:%.6f s\n",cpu);
    return 0;
    
}


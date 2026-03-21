#include<unistd.h>
#include<signal.h>
#include<stdio.h>
#include<sys/time.h>
int real_count=0,virt_count=0;
void real_handler(int s){real_count++;}
void virt_handler(int s){virt_count++;}
int main(){
    signal(SIGALRM,real_handler);
    signal(SIGVTALRM,virt_handler);
    // 100ms periodic timers
    struct itimerval it={{0,100000},{0,100000}};
    setitimer(ITIMER_REAL,&it,NULL);
    setitimer(ITIMER_VIRTUAL,&it,NULL);
    printf("Burning CPU for ~3 seconds...\n");
    for(volatile long i=0;i<5e9;i++); //CPU intensive loop
    printf("ITIMER_REAL fired:%d times\n",real_count);
    printf("ITIMER_VIRTUAL fired:%d times\n",virt_count);
    return 0;
}

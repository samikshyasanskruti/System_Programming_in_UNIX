#include<unistd.h>
#include<stdio.h>
#include<signal.h>
#include<string.h>
volatile sig_atomic_t stop=0;
void safe_handler(int sig){
     stop=1;
}
int main(){
    struct sigaction sa;
    memset(&sa,0,sizeof(sa));
    sa.sa_handler=safe_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags=SA_RESTART;
    sigaction(SIGINT,&sa,NULL);
   while(!stop){
       write(STDOUT_FILENO,".",1);//safe inside signal context
       sleep(1);
   }
   write(STDOUT_FILENO,"\nGraceful exit.\n",16);
   return 0;
}

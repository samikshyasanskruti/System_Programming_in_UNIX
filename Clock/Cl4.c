#include<stdio.h>
#include<unistd.h>
#include<signal.h>
int pipefd[2];
void signal_handler(int sig) {
     write(pipefd[1],"!",1);
}
int main(){
    pipe(pipefd);
    signal(SIGUSR1,signal_handler);
    printf("Send:Kill -USR1 %d\n",getpid());
    char buf;
    read(pipefd[0],&buf,1);
    printf("Signal received via pipe\n");
    return 0;
}    

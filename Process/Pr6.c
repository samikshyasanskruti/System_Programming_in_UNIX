#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    pid_t pid=fork();
    
    if(pid==0){
       printf("Child executing...\n");
       sleep(2);
       exit(10);
    }
    else{
       int status;
       wait(&status);
       printf("parent child exit code=%d\n",WEXITSTATUS(status));
    }
    return 0;
}

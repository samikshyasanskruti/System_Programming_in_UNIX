#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    pid_t pid=fork();
    
    if(pid>0){
       printf("Parent executing...\n");
       exit(0);
    }
    else{
       sleep(5);
       printf("Child adopted by init:PPID=%d\n",getppid());
    }
 
}

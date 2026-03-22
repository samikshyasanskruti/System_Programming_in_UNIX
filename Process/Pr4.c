#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    pid_t pid=fork();
    
    if(pid==0)
       printf("Child:PID=%d\n",getpid());
    else
       printf("Parent:PID=%d,Child PID=%d\n",getpid(),pid);
    return 0;
}

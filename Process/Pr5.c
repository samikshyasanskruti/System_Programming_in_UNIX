#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    pid_t pid=fork();
    
    if(pid==0){
       execl("/bin/ls","ls","-l",NULL);
       perror("exec failed");
    }
    else
       printf("Parent waiting...\n");
    return 0;
}

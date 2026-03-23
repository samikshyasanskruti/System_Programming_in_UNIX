#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    pid_t pid=fork();
    
    if(pid==0)
       exit(0);
    else{
       printf("parent sleeping,child becomes zoombie...\n");
       sleep(10);
    }
    return 0;
}

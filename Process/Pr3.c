#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
pid_t pid = fork();
if (pid == 0) { // child
printf("[Child] Exiting now\n");
exit(0);
} else if (pid > 0) { // parent
printf("[Parent] Sleeping; child becomes zombie\n");
sleep(15); // long enough to inspect zombies via ps
printf("[Parent] Now waking up and will exit, child will be reaped by init\n");
} else {
perror("fork failed");
return 1;
}
return 0;
}

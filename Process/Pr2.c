#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
pid_t pid = fork();
if (pid == 0) { // child
execl("/bin/ls", "ls", "-l", NULL);
// Only reached on error
perror("execl failed");
_exit(1);
} else if (pid > 0) { // parent
printf("[Parent] Continuing while child runs ls\n");
sleep(1);
} else {
perror("fork failed");
return 1;
}
return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main() {
for(int i=0;i<=2;i++)
{
pid_t pid = fork();
if (pid == 0) { // child
printf("[Child] PID=%d, PPID=%d\n", getpid(), getppid());
sleep(2);
// keep child alive briefly
exit(42);
// child exits with status 42
}
else if (pid > 0) { // parent
int status;
pid_t w = wait(&status); // wait for child to finish
if (w == -1) {
perror("wait");
return 1;
}
if (WIFEXITED(status)) {
printf("[Parent] Child (PID=%d) exited with code=%d\n", w,
WEXITSTATUS(status));
} else {
printf("[Parent] Child terminated abnormally\n");
}
}
else {
perror("fork");
return 1;
}
}
return 0;
}

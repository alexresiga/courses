#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
int pid;
printf("parent: %d\n", getpid());
pid = fork();

if (pid == 0)
{
printf("Child: %d %d\n", getpid(), getppid());
exit(0);
}

sleep(10);

wait(0);
printf("parent again: %d\n", getpid());

return 0;
} 

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
int n;
int fork1 = fork();
int pid = getpid();
if (fork1 == 0)
	printf("Hello from child [PID - %d]\n", pid);
else
	printf("Hello from parent [PID - %d}\n",pid);
return 0;
}

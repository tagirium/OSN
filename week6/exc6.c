#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

//always have error sh: 1: kill: No such process
int main()
{
int n = 1, fd[2];
pipe(fd);
int fork1 = fork();
int fork2 = 1;
if (fork1 > 0)
{		
	fork2 = fork();
	if (fork2 > 0)
	{
		char *str = (char *)calloc(50, sizeof(char));
		sprintf(str, "%d", fork2);
		write(fd[1], str, (strlen(str)));
		printf("WRITE %d\n", fork2);
		waitpid(fork2, &n, 0);
	}
}
else if (fork1 == 0 && fork2 != 0)
{
	sleep(2);
	char* s = (char *)calloc(50, sizeof(char));
	char* s2 = (char *)calloc(50, sizeof(char));
	read(fd[0], s2, sizeof(s2));
	sprintf(s, "kill %s", s2);
	printf("SIGSTOP %s\n", s2);
	system(s);
}
return 0;
}

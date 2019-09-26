#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int main()
{
int n;
int fork1 = fork();
if (fork1 == 0)
	while(1)
	{
		printf("I'm alive\n");
		sleep(1);
	}
else
{
	sleep(10);
	char* s = (char *)calloc(50, sizeof(char));
	sprintf(s, "kill %d", fork1);
	system(s);
}
return 0;
}

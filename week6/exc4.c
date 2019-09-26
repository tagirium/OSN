#include<stdio.h> 
#include<signal.h> 
#define SIGUSR1 10
#define SIGKILL 10
#define SIGINT 10
int flag = 1;

void handle_sigint(int sig)
{
	printf("\nCaught interruption signal %d", sig);
	flag = 0;
}

void handle_sigkill(int sig)
{
	printf("\nCaught kill signal %d", sig);
	flag = 0;
}

void handle_sigusr1(int sig)
{
	printf("\nCaught user signal %d", sig);
}

int main(int argc, char const *argv[])
{
	signal(SIGINT, handle_sigint);
	signal(SIGKILL, handle_sigkill);
	signal(SIGUSR1, handle_sigusr1);
	while(flag) ;
	return 0;
}

// Output: [1]+  User defined signal 1   ./ex4
// User defined signal is SIGUSR1
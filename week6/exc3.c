#include<stdio.h> 
#include<signal.h> 
int flag = 1;

void handle_sigint(int sig)
{
	printf("\nCaught signal %d\n", sig);
	flag = 0;
}

int main(int argc, char const *argv[])
{
	signal(2, handle_sigint);
	while(flag) ;
	return 0;
}
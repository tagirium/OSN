#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main(int argc, char const *argv[])
{
	struct rusage u;
	for (int i = 0; i < 10; ++i)
	{
		int* a = (int*) malloc(10*1024*1024*sizeof(char));
		memset(a,0,10*1024*1024*sizeof(char));
		getrusage(RUSAGE_SELF,&u);
		printf("%ld\n", u.ru_maxrss);
		sleep(1);	
	}
	return 0;
}
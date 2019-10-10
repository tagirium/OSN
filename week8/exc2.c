#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 10; ++i)
	{
		int* a = (int*) malloc(10*1024*1024*sizeof(char));
		memset(a,0,1024*1024*10*sizeof(char));
		sleep(1);	
	}
	return 0;
}
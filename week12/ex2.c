#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int *fds = (int*) calloc(argc-1, sizeof(int));
	int *appends = (int*) calloc(argc-1, sizeof(int));
	for (int i = 1; i < argc; ++i)
	{
		if (argv[i] != "-a")
		{
			if (appends[i-1] == 0)
			{
				fds[i-1] = creat(argv[i], S_IRWXU);
			}
			else
			{
				fds[i-1] = open(argv[i], O_APPEND | O_WRONLY | O_CREAT);
			}
		}
		else if (i != argc)
		{
			appends[i+1] = 1;
		}
		else
		{
			printf("INPUT ERROR\n");
			return 0;
		}
	}
	char s;
	while (read(open("/proc/cpuinfo", O_RDWR), &s, 1) != 0)
	{
		for (int i = 0; i < argc - 1; ++i)
		{
			write(fds[i], &s, 1);
		}
	}
	return 0;
}
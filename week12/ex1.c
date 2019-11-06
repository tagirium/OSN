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
	char *s = (char*) calloc(20, sizeof(char));
	int fd_out = open("ex1.txt", O_RDWR | O_CREAT);
	int fd_random = open("/dev/random", O_RDWR);
	read(fd_random, s, 20);
	ftruncate(fd_out, 20);
	strcpy(mmap(NULL, 20, PROT_WRITE, MAP_SHARED, fd_out, 0), s);
	return 0;
}
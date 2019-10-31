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
	int src = open("ex1.txt", O_RDWR);
	int dest = open("ex1.memcpy.txt", O_RDWR | O_CREAT);
	struct stat buff;
	fstat(src, &buff);
	int length = buff.st_size;
	ftruncate(dest, length);
	memcpy(mmap(NULL, length, PROT_WRITE, MAP_SHARED, dest, 0), mmap(NULL, length, PROT_WRITE, MAP_SHARED, src, 0), length);
	return 0;
}
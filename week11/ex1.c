#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int fd = open("ex1.txt", O_RDWR);
	struct stat buff;
	fstat(fd, &buff);
	int length = buff.st_size;
	char *str = "This is a nice day";
	ftruncate(fd, strlen(str));
	strcpy(mmap(NULL, length, PROT_WRITE, MAP_SHARED, fd, 0), str);
	return 0;
}
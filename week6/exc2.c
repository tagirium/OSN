#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h>

int main(int argc, char const *argv[])
{
	int fd[2], n;
    pid_t childpid;
    char s1[] = "hello\n";
    char *s2  = (char*) calloc(100, sizeof(char));
    pipe(fd);
    if((childpid = fork()) == -1)
    {
        perror("fork");
        exit(1);
    }
    if(childpid == 0)
    {
	close(fd[0]);
	write(fd[1], s1, (strlen(s1)+1));
    exit(0);
    }
    else
    {
    	close(fd[1]);
        n = read(fd[0], s2, sizeof(s2));
        printf("Received string: %s", s2);
	}
    return(0);
}
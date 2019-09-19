#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *threadPrint(void *vargp)
{
	printf("Thread #%d\n", *(int*)vargp);

}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	pthread_t thread[n];
	for (int i = 0; i < n; ++i)
	{
		pthread_create(&thread[i], NULL, threadPrint, &i);
		//Solution:
		//here should be
		//pthread_join(thread[i], NULL);
		//printf(" - Should be: %d\n", i);
	}
	for (int i = 0; i < n; ++i)
	{
		pthread_join(thread[i],NULL);
	}
	return 0;
}
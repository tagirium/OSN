#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int count = 0, consumer_sleep = 1, producer_sleep = 0;

void *producer(void *vargp)
{
	while (1)
	{
		while (producer_sleep) ;
		count++;
		if (count >= * (int*)vargp)
		{
			consumer_sleep = 0;
			producer_sleep = 1;
		}
	}
}

void *consumer(void *vargp)
{
	while (1)
	{
		while (consumer_sleep) ;
		count--;
		if (count <= 0)
		{
			consumer_sleep = 1;
			producer_sleep = 0;
		}	
	}
}

int main(int argc, char const *argv[])
{
	int n, i = 0;
	scanf("%d", &n);
	pthread_t cons, prod;
	pthread_create(&prod, NULL, producer, &n);
	pthread_create(&cons, NULL, consumer, &n);
	while(++i && i < 1000)
	{
		printf("Consume - %d | Producer - %d | Count - %d\n", consumer_sleep, producer_sleep, count);
		sleep (1);
	}
	pthread_join(cons,NULL);
	pthread_join(prod,NULL);

	return 0;
}
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int* arr = (int*) calloc(n,sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		arr[i] = i;
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n", arr[i]);
	}
	free(arr);
	arr = NULL;
	return 0;
}
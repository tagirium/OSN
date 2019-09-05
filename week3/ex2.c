#include <stdio.h>
void swap (int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

int main()
{
	int arr[] = {5,2,7,1,2,6,3};
	int n = sizeof(arr)/sizeof(int);
	printf("Before sort:\n");
	for (int i = 0; i < n; i++)
		printf ("%d ", arr[i]);
	printf("\nAfter sort:\n");
	bubbleSort(arr,n);
	for (int i=0; i < n; i++)
        	printf("%d ", arr[i]);
}

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	FILE *fp;
	if ((fp = fopen("input.txt", "r"))==NULL) 
	{
		printf("Cannot open file.\n");
		exit(1);
	}
	int n = 100 , hit = 0, miss = 0;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		arr[i] = 0;
	}
	unsigned char old[n];
	int inp = 0, has = 0, has_num = 0;;
	for (int i = 0; i < n; ++i)
	{
		old[i] = 0;
	}
	while(fscanf(fp,"%d",&inp) != 0 && !feof(fp))
	{
		for (int i = 0; i < n; ++i) //searching in the array for same page frame
		{
			if (arr[i] == inp)
			{
				has = 1;
				has_num = i;
				hit++;
				break;
			}
		}
		if (!has) //if we didn't find, then go through
		{		
			int empty = 1;
			for (int i = 0; i < n; ++i)
			{
				if (arr[i] == 0)
				{
					arr[i] = inp;
					for (int j = 0; j < n; ++j)
					{
						old[j] = old[j]>>1;
					}
					old[i] = 128;
					empty = 0;
					break;
				}
			}
			if (empty)
			{
				int oldest = old[0], oldest_num = 0;
				for (int i = 1; i < n; ++i) // searching for the oldest element
				{
					if (oldest > old[i])
					{
						oldest = old[i];
						oldest_num = i;
					}
				}
				arr[oldest_num] = inp;
				for (int i = 0; i < n; ++i)
				{
					old[i] = old[i]>>1;
				}
				old[oldest_num] = 128;
			}
			miss++;
		}
		else // if we found, then increase his priority to not be removed
		{
			for (int i = 0; i < n; ++i)
			{
				old[i]>>1;
			}
			old[has_num] = old[has_num] | 128;
		}
		has = 0;	
		has_num = 0;
	}
	printf("%f\n", (float)(hit)/miss);
	return 0;
}
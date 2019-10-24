#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char const *argv[])
{
	DIR *dirp = opendir("tmp");
	int num_of_files = 0;
	if (dirp == NULL)
	{
		printf("ERROR 1\n");
	}
	else
	{
		struct dirent* dp;
		while ((dp = readdir(dirp)) != NULL)
		{
			num_of_files++;
		}
	}
	closedir(dirp);
	dirp = opendir("tmp");
	ino_t i_nums[num_of_files];
	char names[num_of_files][256];
	int count=0;
	if (dirp == NULL)
	{
		printf("ERROR 2\n");
	}
	else
	{
		struct dirent* dp;
		FILE *fp = fopen("ex4.txt","w");
		while ((dp = readdir(dirp)) != NULL)
		{
			i_nums[count] = dp->d_ino;
			strcpy(names[count], dp->d_name);
			count++;
		}
		ino_t res[num_of_files];
		count = 0;
		for (int i = 0; i < num_of_files; ++i)
		{
			res[i] = 0;
		}
		for (int i = 0; i < num_of_files - 1; ++i)
		{
			for (int j = i + 1; j < num_of_files; ++j)
			{
				if (i_nums[i]==i_nums[j])
				{
					for (int k = 0; k < num_of_files; ++k)
					{
						if (res[k] == i_nums[i])
						{
							goto next_it;
						}
					}
					res[count] = i_nums[i];
					count++;
					next_it: continue;
				}
			}
		}
		for (int i = 0; i < count; ++i)
		{
			fprintf(fp, "%d: ", (int)res[i]);
			for (int j = 0; j < num_of_files; ++j)
			{
				if (res[i]==i_nums[j])
				{
					fprintf(fp, "%s\n", names[j]);
				}
			}
		}
	}
	
	return 0;
}
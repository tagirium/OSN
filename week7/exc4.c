#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

void * my_realloc(void * ptr, size_t size)
{
	if (size == 0)
	{
		free(ptr);
		return NULL;
	}
	else if (ptr == NULL)
	{
		return malloc(size);
	}
	else
	{
		void * new_ptr = malloc(size);
		if (new_ptr)
		{
			memcpy(new_ptr, ptr, malloc_usable_size(ptr));
			free(ptr);
		}
		return new_ptr;
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
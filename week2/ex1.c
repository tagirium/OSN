#include <stdio.h>
#include <limits.h>
#include <float.h>
int main()
{
	int a;
	float b;
	double c;
	a = INT_MAX;
	b = FLT_MAX;
	c = DBL_MAX;
	printf("int: %d | %lu\n", a, sizeof(a));
	printf("float: %f | %lu\n", b, sizeof(b));
	printf("double: %lf | %lu\n", c, sizeof(c));

}

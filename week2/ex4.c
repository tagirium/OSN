#include <stdio.h>
int swap(int* a, int* b){
	int c = *a;
	*a = *b;
	*b = c;
}

int main(){
	int a, b;
	scanf("%d%d",&a,&b);
	swap(&a, &b);
	printf("a = %d, b = %d", a, b);
	return 0;
}

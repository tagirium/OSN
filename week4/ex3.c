#include <stdlib.h>
int main()
{
char *s = (char*)malloc(20*sizeof(char));
while(1){
gets(s);
system(s);
}
}

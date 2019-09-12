#include <stdio.h>
#include <stdlib.h>
int main(){
char *s = calloc(200,sizeof(char));
while(1)
{
gets(s);
system(s);
}
}

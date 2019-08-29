#include <stdio.h>
#include <string.h>
int main(){
printf("Enter a string\n");
char str[128];
gets(str);
for (int i = strlen(str) - 1;i>=0;i--)
printf("%c",str[i]); 
return 0;
}

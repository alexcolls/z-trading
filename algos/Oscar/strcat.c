#include <stdio.h>
#include <string.h>
 
int main()
{
  char* a[1000], b[1000];
 
  printf("A");
  gets(a);
 
  printf("B");
  gets(b);
 
  strcat(a, b);
 
  printf(a);
 
  return 0;
}
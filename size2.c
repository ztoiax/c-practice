#include <stdio.h>
#define size(n) printf(#n"= %zd\n",sizeof(n));
int main(void)
{
  int * pointer;

  printf("int = %zd\n",sizeof(int));
  printf("short = %zd\n",sizeof(short));
  printf("long = %zd\n",sizeof(long));
  return 0;
}

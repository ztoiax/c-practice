#include <stdio.h>
#define size(n) printf(#n"= %zd\n",sizeof(n));
int main(void)
{
  int * pointer;

  size(short);
  size(int);
  size(long int);

  size(unsigned short);
  size(unsigned int);
  size(long unsigned int);

  size(float);
  size(double);
  size(long double);

  size(pointer);
  return 0;
}

//free后在malloc,地址并没有改变
#include "tlpi_hdr.h"

int main(void)
{
  int *p;

  p = (int *) malloc(4);
  *p = 1;
  printf("frist:p=%d  %p\n", *p, p);

  free(p);
  p = (int *) malloc(4);
  *p = 2;
  printf("after:p=%d  %p\n", *p, p);

  free(p);
  return 0;
}

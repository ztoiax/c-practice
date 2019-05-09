//char 转换unsigned
#include <stdio.h>
int main(void){
  char c[10];
  long *p =(long *)&(c[0]);

  *p = 127;
  printf("%u\n",c[0]);
  *p = 128;
  printf("%u\n",c[0]);

  *p = 127;
  printf("%d\n",c[0]);
  *p = 128;
  printf("%d\n",c[0]);
  return 0;
}

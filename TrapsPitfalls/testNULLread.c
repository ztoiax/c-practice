//在禁止读取内存地址0的机器上,会执行失败
#include <stdio.h>
int main(void){
  char *p;
  p = NULL;
  printf("p = %d\n",*p);
  return 0;
}

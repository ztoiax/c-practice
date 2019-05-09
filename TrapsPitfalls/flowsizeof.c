//会报错的sizeof溢出
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int array[] = {1,2};
#define TOTAL (sizeof(array) / sizeof(array[0]))
int main(int argc, char **argv){
  int i;
  i = TOTAL - 3;
  printf("i = %d\n",i);
  return 0;
}

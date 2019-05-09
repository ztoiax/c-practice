#include <stdio.h>
#define sign(a) (a) >= 0 && ~a < 0
#define type(a) (a)0 - 1 < 0

int main(void){
  int i = 1;
  if(sign(i))
    printf("is sign int\n");
  if(type(char))
    printf("is sign type\n");
  return 0;
}

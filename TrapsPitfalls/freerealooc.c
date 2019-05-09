//realloc在free后仍能执行,执行必须早
#include <stdio.h>
#include <stdlib.h>
int main(void){
  char *p;
  p = (char *)malloc(sizeof(char));
  free(p);
  p = (char *)realloc(p,sizeof(int));

  *p = 1;
  printf("p = %d\n",*p);
  return 0;
}

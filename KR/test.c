#include <stdio.h>
#include <string.h>
#include "my_string.h"

int main(int argc, char *argv[]){
  char s[] = "tz";
  char s1[10];
  int i;
  i = my_getline(s,10);
  printf("i = %d\n",i);
  my_fputs(s,stdout);

  my_strcopy(s1,s);
  printf("s1 = %s\n",s1);

  i = my_strcmp(s1,s);
  printf("i = %d\n",i);

  i = my_getchar();
  printf("c = %c\n",i);

  i = my_bufgetchar();
  printf("bufc = %c\n",i);
  i = my_bufgetchar();
  printf("buf1c = %c\n",i);

  return 0;
}

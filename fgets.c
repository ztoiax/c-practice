//fgets函数测试

#include<stdio.h>
#define NUM 11

char * process(char *zfc,int n);

int main (void)
{
  char zfc[NUM];
 while(fgets(zfc, NUM, stdin) != NULL && zfc[0] != '\n')
 {
  process(zfc,NUM);
  fputs(zfc,stdout);
 }
 puts("done");
 return 0;
}

char * process(char *zfc,int n)
{
  int i = 0;
  while(zfc[i] != '\n' && zfc[i] != '\0')
    i++;

    if(zfc[i] == '\n')
       zfc[i] = '\0';
    else
    {
       while(getchar() != '\n')
         continue;
    }
  return zfc;
}

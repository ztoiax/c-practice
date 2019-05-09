//第十章
//获取当前时间time()
//并输出ctime()
//分解结构localtime(),gmtime()
//再以%c格式输出strftime()
#include "tlpi_hdr.h"
#include <time.h>

int main(int argc, char *argv[]){
  char s[1000];
  char *c;
  time_t i;
  struct tm *tm;

  i = time(NULL);
  c = ctime(&i);
  puts(c);

  tm = localtime(&i);
  if(tm == NULL)
    printf("error");
  strftime(s,1000,"%c",tm);
  puts(s);
  return 0;
}

#include <stdio.h>
int b(void);
    int main ()
    {
      char *p;
      p = b();
      printf("p = %s\n",*p);
      return 0;
    }
char *b(void){
  char cline[]="test";
  return cline;
}

#include <stdio.h>
#include "fopen.h"

int main(void){
  FILES *fp;
  char c;
  if((fp = my_fopen("test","a")) == NULL )
    printf("open error\n");

  if((c = GETC(fp)) == EOF)
    printf("GETCHAR error\n");

  printf("c = %c\n",c);

  if(my_fseek(fp, -2L, 1))
    printf("fseek error\n");

  PUTC(c,fp);
  if((c = GETC(fp)) == EOF)
    printf("GETCHAR error\n");
  printf("c = %c\n",c);

  my_fclose(fp);

  return 0;
}

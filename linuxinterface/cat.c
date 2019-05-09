#include <stdio.h>
int main(int argc, char **argv){
  FILE *fp;
  int i = 0;
  if(argc == 1)
    fprintf(stderr,"please input file\n");
  else
    while(--argc > 0)
      if((fp = fopen(*++argv,"r")) == NULL){
        fprintf(stderr,"can't open file: %s\n",*argv);
        i = 1;
      }else{
        int c;
        while((c = getc(fp)) != EOF)
          putc(c,stdout);
        fclose(fp);
      }
  return i;
}

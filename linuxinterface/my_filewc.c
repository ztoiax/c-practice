#include <fcntl.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

struct {
    unsigned ch;
    unsigned word;
    unsigned line;
}count;

int wc (char *name);
int main(int argc, char *argv[])
{
  int c;
  int n = 0;
  char path[10][1024];

  if (strcmp(argv[1], "-i") == 0){
      for (int i = 0;; i++){
          c = getchar();
          path[n][i] = c;
          if (path[n][0] == '\n')
              break;
          if (path[n][i] == '\n'){
              path[n][i] = '\0';
              i = -1;
              n++;
          }
      }
      if (n > 0)
          for (int i = 0; i < n; i++){
              wc(path[i]);
              printf("FILE:%s\nchar:%d,word:%d,line:%d\n", path[i], count.ch, count.word, count.line);
              putchar('\n');
          }
  } else if (argc > 1){
        while (--argc > 0){
            wc(*++argv);
            printf("FILE:%s\nchar:%d,word:%d,line:%d\n", *argv, count.ch, count.word, count.line);
            putchar('\n');
        }
  } else if (argc == 1){
      wc("/dev/fd/0");
      printf("char:%d,word:%d,line:%d\n", count.ch, count.word, count.line);
  }
  return 0;
}

int wc (char *name)
{
  FILE *fp;
  int state ,c;
  enum { OUT, IN };

  count.ch = count.word = count.line = 0;
  if ((fp = fopen(name,"r")) == NULL){
      fprintf(stderr, "error: can't open file %s\n", name);
      exit(EXIT_FAILURE);
  }
  while ((c = getc(fp)) != EOF){
      count.ch++;
      if (c == '\n')
          count.line++;
      if (c == '\t' || c == ' ' || c == '\n')
          state = OUT;
      else if (state == OUT && isalpha(c)){
          state = IN;
          count.word++;
      }
  }
  fclose(fp);
  return 0;
}

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define BUFSIZE 1024

char *my_fgets(char *s, int n, FILE *iop){
  register char c;
  register char *pc;

  pc = s;
  while (--n >= 0 && ((c = getc(iop)) != EOF))
    if((*pc++ = c) == '\n')
      break;
  *pc = '\0';
  return (c == EOF && pc == s) ? NULL : s;
}

int my_fputs(char *s, FILE *iop){
  char c;
  const char *p = s;
  while((c = *p) != '\0'){
    p++;
    putc(c,iop);
  }
  return ferror(iop) ? EOF : 1;
}

int my_strlen(char *s){
  char *p = s;
  while(*p != '\0')
    p++;
  return p - s;
}

void my_strcopy(char *t, char *f){
  while((*t = *f) != '\0'){
    t++; f++;
  }
  *++t = '\0';
}

int my_strcmp(char *t, char *f){
  while(*t == *f){
    if('\0' == *t)
      return 0;
    t++; f++;
  }
  return *t - *f;
}

int my_getline(char *line, int n){
  if(my_fgets(line, n, stdin) == NULL)
    return 0;
  else
    return my_strlen(line);
}

int my_getchar(void){
  char c;
  return (read(0,&c,1) == 1) ? c : EOF;
}

int my_bufgetchar(void){
  static char buf[BUFSIZE];
  static char *bufp;
  static int n = 0;

  if(!n){
    n = read(0,buf,BUFSIZE);
    bufp = buf;
  }
  return (--n >=0 ? *bufp++ : EOF);
}

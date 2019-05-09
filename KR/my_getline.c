#include <stdio.h>
#define BUF 1024

int my_getline(char cline[], int ilimit);
int copy(char cline[], char cmax[]);

int  main(void){
  int c, icount, imax;
  char cline[BUF], cmax[BUF];
  imax = 0;

  while((icount = my_getline(cline, BUF)) > 0){
    if(icount > imax){
      imax = icount;
      copy(cline, cmax);
    }
  }
  if(imax > 0)
    printf("%s\n",cmax);
  return 0;
}

int my_getline(char cline[], int ilimit){
  int i, c;
  for(i = 0; i < ilimit-1 && (c = getchar()) != EOF && c != '\n'; i++){
    cline[i] = c;
    if(c == '\n')
      cline[i]++;
  }
  cline[i] = '\0';
  return i;
}

int copy(char cline[], char cmax[]){
  int i = 0;
  while((cmax[i] = cline[i]) != '\0')
    i++;
  return 0;
}

#include <stdio.h>
#include <string.h>
#define BUF 1024
double my_atof(char *a);
int my_getline(char cline[], int ilimit);

int  main(int argc, char *argv[]){
  char cline[BUF];
  double dcount;
  while(my_getline(cline,BUF) > 1)
    dcount += my_atof(cline);
  printf("%f\n",dcount);
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

double my_atof(char *a){
  double f;
  int n, i = 1;
  if(*a == '-'){
    i = -1;
    a++;
  }

  for(f = 0; *a >= '0' && *a <= '9' && *a != '.'; a++){
    f = f * 10 + *a - '0';
  }
  if(*a == '.')
    a++;
  for(n = 1.0; *a >= '0' && *a <= '9' && *a != '.'; a++){
    f = f * 10 + *a - '0';
    n *= 10.0;
  }
    return f / n * i;
}

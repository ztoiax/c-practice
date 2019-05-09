#include <stdio.h>
#include <string.h> 

double my_atof(char *a);
int my_ftoa(double f, char a[],int n);
int hta(char a[]);

int main(int argc, char *argv[]){
  char a[1024];
  double f;
  f = my_atof(argv[1]);
  printf("my_atof = %f\n",f);
  my_ftoa(f,a,3);
  printf("my_ftoa = %s\n",a);
  return 0;
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

int my_ftoa(double f, char a[], int n){
  int i, j, d, c;
  if(f < 0 ){
    d = 1;
    f = -f;
  }
  c = n;
  for(; n > 0; n--)
    f *= 10;

  for(j = 0, i = (int)f; i > 0; j++, i /= 10){
    if(j == c)
      a[j++] = '.';
    a[j] = i % 10 + '0';
  }

  if(d == 1)
    a[j++] = '-';
  a[j] = '\0';
  hta(a);
  return 0;
}

int hta(char a[]){
  int i, j, c;
  for(i = 0, j = (strlen(a) -1); i < j; i++, j--){
    c = a[j]; a[j] = a[i]; a[i] = c;}
  return 0;
}

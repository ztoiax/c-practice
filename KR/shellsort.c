#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUF 1024

int copy(char a[], char c[]);
void my_shellsort(char c[], int i);
void line(char c[]);

int  main(int argc, char *argv[]){
  int i;
  char c[BUF];
  i = copy(argv[1],c);
  printf("first:%s\n",c);
  line(c);
  my_shellsort(c, i);
  printf("end:%s\n",c);
  return 0;
}

int copy(char a[], char c[]){
  int i = 0;
  while(c[i] = a[i])
    i++;
  c[i] = '\0';
return i - 1;
}
void my_shellsort(char c[], int i){
  int gap, n, j, temp;
  int in = 0;

  for(gap = i / 2; gap > 0 ; gap /= 2)
    for(n = gap; n  <= i; n++)
      for(j=n-gap; j>=0 && c[j] > c[j+gap]; j-=gap){
        temp = c[j]; c[j] = c[j+gap]; c[j+gap] = temp;
        printf("%d:%s\n",in++,c);
        line(c);
      }
}

void line(char c[]){
  int i, x, in;

  for(i = 0; (in = (c[i] - '0')) <= strlen(c); i++){
    for(x = in; x > 0; x--)
      putchar('*');
    putchar('\n');
    }
  putchar('\n');
}

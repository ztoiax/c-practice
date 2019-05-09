#include <stdio.h>
#include <string.h>
#define BUF 1024
int in = 1;

int copy(char a[], char c[]);
void qsort(char v[], int left, int right);
void swap(char v[], int i, int j);
void line(char c[]);

int  main(int argc, char *argv[]){
  int i;
  char c[BUF];
  i = copy(argv[1],c);
  printf("first:%s\n",c);
  line(c);

  qsort(c, 0, strlen(c)-1);
  printf("end:%s\n",c);
  line(c);
  return 0;
}

int copy(char a[], char c[]){
  int i = 0;
  while((c[i] = a[i]) != '\0')
    i++;
  c[i] = '\0';
return i - 1;
}
void qsort(char v[], int left, int right){
  int i, last;
  if (left > right)
    return;
  swap(v, left , (left + right) / 2);
  last = left;
  for(i = left + 1; i <= right; i++){
    if(v[i] < v[left]){
       swap(v, ++last, i);
       printf("%d:%s\n",in++,v);
       line(v);
    }
  }
  swap(v, left, last);
  qsort(v,left, last-1);
  qsort(v,left+1, right);
}

void swap(char v[], int i, int j){
  int temp;

  temp = v[i];
  v[i] = v [j];
  v[j] = temp;
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

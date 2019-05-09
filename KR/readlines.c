#include <stdio.h>
#include <string.h>
#define BUF 1024
char *pline[BUF];

int readlines(char *pline[], int icount);
void writelines(char *pline[], int icount);
void qsort(char *v[], int left, int right);
void swap(char *v[],int left,int right);
int my_strcmp(char *p, char *pc);

int my_getline(char c[], int icount);
void my_strcpy(char *p, char *pc);

char * alloc(int i);
void afree(char *p);

int main(int argc, char *argv[]){
  int i;
  int n = 0;
  if((i = readlines(pline,BUF)) > 0){
    while(--i > 0)
    qsort(**pline++, 0,5);
    writelines(pline, i);
    return 0;
  }
  else{
    printf("error\n");
    return 1;
  }
}

int my_getline(char c[], int icount){
  int i; char n;
  for(i = 0;i < icount-1 && (n = getchar()) != EOF && n != '\n'; i++)
    c[i] = n;
  c[i] = '\0';
  return i;
}
#define LEN 1000

int readlines(char *pline[], int icount){
  int i,in;
  char *p, cline[LEN];
  in = 0;
  while((i = my_getline(cline,LEN)) > 1){
    if(in >= icount || (p = alloc(i)) == NULL)
     return -1;
    else{
     my_strcpy(p,cline);
     pline[in] = p;
     in++;
    }
  }
  return  in;
}

void writelines(char *pline[], int icount){
  int i;
  for(i = 0; i < icount && *pline[i] != '\0'; i++)
    printf("%s\n",pline[i]);
}

void my_strcpy(char *p, char *pc){
  while((*p++ = *pc++) != '\0')
    continue;
}
#define ASIZE 10000

static char abuf[ASIZE];
static char *pa = abuf;

char * alloc(int i){
  if(abuf + ASIZE - abuf > i){
    pa += i;
    return pa - i;
  }
  else
    return 0;
}

void afree(char *p){
  if(p >= abuf && p <= abuf + ASIZE)
    pa = p;
}

void qsort(char *v[], int left, int right){
  int i, last;
  if (left > right)
    return;
  swap(v, left , (left + right) / 2);
  last = left;
  for(i = left + 1; i <= right; i++){
    if(my_strcmp(v[i], v[left]) < 0){
       swap(v, ++last, i);
    }
  }
  swap(v, left, last);
  qsort(v,left, last-1);
  qsort(v,left+1, right);
}

void swap(char *v[],int left,int right){
  char *temp;
  temp = v[right]; v[right] = v[left]; v[left] = temp;
}

int my_strcmp(char *p, char *pc){
  for(;*p == *pc; p++, pc++)
    if(*p == '\0')
      return 0;
  return *p - *pc;
}

#include <stdio.h>
#include <string.h>
#define BUF 1024
int my_getline(char [], int);
void order(char [],int);
void swap(char cline[], int a, int b);
void neworder(char cline[],int ichar);
static int inumber = 0;

int main(int argc, char *argv[]){
  char cline[BUF];
  int i;
  if(!(i = my_getline(cline,BUF)))
    printf("error my_getline");
  else
    order(cline,1);
  return 0;
}
int my_getline(char cline[],int limit){
  char c;
  int i;
  for(i = 0; (c = getchar()) != EOF && c != '\n' && i < limit-1; i++)
    cline[i] = c;
  cline[i] = '\0';
  return i;
}

void order(char cline[],int ichar){
  int i;
  for(i = 2; cline[i] != '\0'; i++){
    swap(cline,i-1,i);
    printf("         %s\n",cline);
  }
  ichar++;
  if(ichar < i)
    order(cline,ichar);
  if(ichar == i)
    neworder(cline,ichar);
}

void swap(char cline[], int a, int b){
  char c;
  c = cline[a]; cline[a] = cline[b]; cline[b] = c;
}
void neworder(char cline[],int ichar){
  if(inumber == 0)
    inumber = ichar;
  printf("%d:\n",inumber);
  swap(cline,0,1);
  if(--inumber)
    order(cline,0);
}

#include <stdio.h>
#include <string.h>
#define BUF 1024
int my_getline(char cline[], int ilimit);
int strindex(char cline[], char cindex[],int ia);

int main(int argc, char *argv[]){
  int i;
  char cline[BUF], cindex[BUF];
  printf("index:");
  i = my_getline(cindex,BUF);
  while(my_getline(cline,BUF) > 1){
    if(strindex(cline,cindex,i) >= 0)
      ;
  }
  return 0;
}

int my_getline(char cline[], int ilimit){
  int i = 0;
  char c;
  while(ilimit-- > 0 && (c = getchar()) && c != EOF && c != '\n')
    cline[i++] = c;
  if(c == '\n')
    cline[i++] = '\n';
  cline[i] = '\0';
  return i;
}

int strindex(char cline[], char cindex[],int ia){
  int i,j,n;
  for(i = 0; cline[i] != '\0'; i++){
    for(j = i,n = 0; cindex[n] != '\0' && cline[j] == cindex[n]; j++, n++)
      continue;
    if(n > 0 && cindex[n] == '\0'){
      printf("index:%s",cline);
      return i;
    }
  }
  return -1;
}

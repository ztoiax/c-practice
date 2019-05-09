#include <stdio.h>
#include <string.h>

int main(void){
  int c, i, iwhite , iother;
  int idigit[10];
  iwhite = iother = 0;

  for(i = 0; i < 10; i++)
    idigit[i] = 0;

  while((c =  getchar()) != EOF){
    if(c >= '0' && c <= '9')
      ++idigit[c - '0'];
    else if(c == ' ' || c == '\n'  || c == '\t')
      iwhite++;
    else
      iother++;
  }
  printf("digit:");
  for(i = 0; i < 10; i++)
    printf("%d",idigit[i]);
  printf("white space = %d, other = %d\n",iwhite, iother);
  return 0;
}

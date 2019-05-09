#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  int i = 11;
  int ic = atoi(argv[1]);
  int icount = 0;
  printf("1\t2\t3\t5\t7\t");
  for(; i <= ic; i++){
    if(i % 2 != 0 && i % 5 != 0 && i % 3 != 0 && i % 7 != 0){
    icount++;
    printf("%d\t",i);
    }
  }
  putchar('\n');
  printf("总共%d\n",icount + 5);
}

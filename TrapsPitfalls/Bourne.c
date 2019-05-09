#include <stdio.h>
#define INT int
#define IF if(
#define THEN ){
#define FI }
#define ELSE }else{

#define WHILE while(
#define DO ){
#define OD }

#define BEGIN {
#define END }

int main(int argc, char *argv[]){
  INT i = '0';
  INT n = 1;
  IF argc == 3
  THEN 
      WHILE i < *argv[2]
      DO
        n *= *argv[1] - '0';
        i++;
      OD
      printf("%d\n",n);
  ELSE
      printf("error\n");
  FI
}
/*
void test(void){
  int i = '0';
  int n = 1;
  if (argc == 3){
     while (i < *argc[2]){
       n *= *argv[1] - '0';
       i++;
     }
    printf("%d\n",n);
  }
  else
    printf("error\n");
}
*/

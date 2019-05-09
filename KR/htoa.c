#include <stdio.h>
#include <string.h>
#define BUF 1024

int my_atoh(char c[]);
int my_htoa(int in, char c[]);
int hta(char a[]);

int  main(int argc, char *argv[]){
  int i;
  char c[BUF];
  i = my_atoh(argv[1]);
  printf("my_atoh = %d\n",i);
  my_htoa(i,c);
  printf("my_htoa = %s\n",c);
  return 0;
}

int my_atoh(char c[]){
  int i, ih;
  int isign = 1, icount = 0;
  if(c[0] == '-')
    isign = -1;

  for(i = 0; c[i] != '\0'; i++){
    if(c[i] >= 'a' && c[i] <= 'f'){
      switch(c[i]){
       case 'a':ih = 10; break;
       case 'b':ih = 11; break;
       case 'c':ih = 12; break;
       case 'd':ih = 13; break;
       case 'e':ih = 14; break;
       case 'f':ih = 15; break;
       }
      icount = 16 * icount + ih;
    }
    else if(c[i] >= '0' && c[i] <= '9')
      icount = 16 * icount + (c[i] - '0');
    else
      printf("err!\n");
  }
return icount * isign;
}

int my_htoa(int in, char c[]){
  int i, isign;
  if(in < 0 ){
    isign = 1;
    in = -in;
  }


  for(i = 0; in > 0; i++, in /= 16){
    switch(in % 16){
      case 10: c[i] = 'a'; break;
      case 11: c[i] = 'b'; break;
      case 12: c[i] = 'c'; break;
      case 13: c[i] = 'd'; break;
      case 14: c[i] = 'e'; break;
      case 15: c[i] = 'f'; break;
      case 1: c[i] = '1'; break;
      case 2: c[i] = '2'; break;
      case 3: c[i] = '3'; break;
      case 4: c[i] = '4'; break;
      case 5: c[i] = '5'; break;
      case 6: c[i] = '6'; break;
      case 7: c[i] = '7'; break;
      case 8: c[i] = '8'; break;
      case 9: c[i] = '9'; break;
      case 0: c[i] = '0'; break;
    }
  }

  if(isign == 1)
    c[i++] = '-';
  c[i] = '\0';
  hta(c);
return 0;
}

int hta(char a[]){
  int i, j, c;
  for(i = 0, j = (strlen(a) -1); i < j; i++, j--){
    c = a[j]; a[j] = a[i]; a[i] = c;}
  return 0;
}

#include <stdio.h>

void binary (int i){
  char s[33];
  int n,a;
  for (n = 0; i >= 1; n++, i >>= 1){
      a = 0;
      if(i % 2)
        a = 1;
      s[n] = a;
  }
    s[n++] = '\0';
}

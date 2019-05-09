#include <stdio.h>

void binary (int i){
  char s[33];
  int n;
  for (n = 0; i >= 1; n++, i >>= 1){
      s[n] = ((i % 2) ? '1' : '0');
  }
    s[n++] = '\0';
}

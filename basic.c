/* basic.c */
#include <stdio.h>
#include <string.h>
typedef unsigned char * byte_pointer;

void show_bytes (byte_pointer start, size_t len); //以十六进制打印每个字节
void binary (int i);                              //转换二进制
void binary32 (int i);
void h2t (char s[]);
int tadd_ok(int x, int y);                        //检查整数加分是否溢出
int muti_ok(int x, int y);
int fun_a(unsigned x);                            //奇数个1,返1

void show_bytes (byte_pointer start, size_t len){
  size_t i;
  for (i = 0; i < len; i++)
      printf(" %.2x",start[i]);
  printf("\n");
}

void binary32 (int i){
  unsigned n = 0;
  unsigned mask = 1 << 31;
  while(mask != 0){
      n++;
      putchar((i & mask) ? '1' : '0');
      mask >>= 1;
      if(n % 8 == 0)
        putchar(' ');
  }
    putchar('\n');
}

void binary (int i){
  char s[33];
  int n;
  for (n = 0; i >= 1; n++, i >>= 1){
      s[n] = ((i % 2) ? '1' : '0');
  }
    s[n++] = '\0';
    h2t(s);
    printf("%s\n",s);
}

void h2t (char s[]){
  int c,i,j;
  for (i = 0, j = strlen(s)-1; i < j; i++, j--){
      c = s[i]; s[i] = s[j]; s[j] = c;
  }
}

int tadd_ok (int x, int y){
  int sum = x + y;
  int neg_over = x < 0 && y < 0 && sum >= 0;
  int pos_over = x > 0 && y > 0 && sum <= 0;
  return !neg_over && !pos_over;
}

int muti_ok (int x, int y){
  __int64_t sum = (__int64_t) x * y;
  return sum == (int) x * y;
}

int fun_a (unsigned x){
  int i = 0;
  while(x){ i ^= x; x >> 1;}
  return i & 0x1;
}

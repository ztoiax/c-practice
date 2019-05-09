/* 正方形 */
#include <stdio.h>
#define N 30

int main (void)
{
  int i;
  int n;
  for(i = 0; i < N / 2; i++)
  {
    for(n = 0; n < 2 * N; n++)
          putchar(n >= N ? '*' : ' ');
  putchar('\n');
  }
  return 0;
}

/* 图形 */
#include <stdio.h>
#define N 30

int square(void);
int triangle(void);
int circle(void);

int main (int argc,char *argv[])
{
  int c;
  int d,s,t;
  if(argc == 1)
  {
    d = 1;
    printf("-s output square \n-t output triangle \n");
    square();
    triangle();
    circle();
  }

      while (--argc > 0 && (*++argv)[0] == '-')
        while (d = *(++argv[0]))
           switch(d) {
           case 's':
                 s = square();
                 break;
           case 't':
                 t = triangle();
                 break;
           case 'c':
                 c = circle();
                 break;
           default:
                 printf("-s output square \n-t output triangle \n");
                 square();
                 triangle();
                 break;
           }

    return 0;
}

int square(void)
{
    int i,n;
    for(i = 0; i < N / 2; i++)
    {
      for(n = 0; n < 2 * N; n++)
          putchar((n >= N) ? '*' : ' ');
          putchar('\n');
    }
    putchar('\n');
    return i;
}


int triangle(void)
{
    int i,n;
    for(i = 0; i <= N / 2; i++)
    {
      for(n = 0; n < 2 * N - i; n++)
          putchar((n <= N + i) ? ' ' : '*');
          putchar('\n');
    }
    return i;
}

int circle(void)
{
    double i,n;
    double pai = 3.1415926;
    for(i = 0; i <= N; i++)
    {
      for(n = 0; ((i >= 0) ? n <= pai * i : n < i * pai); n++)
          putchar('*');
          putchar('\n');
          putchar('\n');
    }
    return i;
}

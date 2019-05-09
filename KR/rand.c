#include <stdio.h>
#include <stdlib.h>
#define frand() ((double)my_rand() / (RAND_MAX+1.0))//RAND_MAX == 2^31 - 1

unsigned long int next = 1;
int my_rand(void){
  next = next * 1103515245 + 12345;
  return next / 65535 % 100;
}

unsigned my_srand(unsigned seed){
  static unsigned d = 1;
  next = seed;
  d = my_rand();
  return d;
}

int main(){
  unsigned d = 1;
  for(int i=0;i<10;i++){
  d = my_srand(d);
  printf("d = %d\n",d);
  }
  return 0;
}

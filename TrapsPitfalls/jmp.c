//和goto一样不易于调试,不是特别需要,不要使用
#include <stdio.h>
#include <setjmp.h>
jmp_buf j;
void b(void);
int main(void){
  int i;
  if(i = setjmp(j)){
    printf("i = %d\n",i);
    printf("back main\n");
  }
  else{
    printf("ie = %d\n",i);
    printf("go b()\n");
    b();
  }
  return 0;
}

void b(void){
  longjmp(j,1);
  printf("longjmp fail\n");
}

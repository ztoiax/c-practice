//union 顺序不同输出不同
#include<stdio.h>
int v();
int main(){
  union {
      float f;
      double d;
  }u;
  u.f = 10.0;
  u.d = 10.0;
  printf("f = %f\n",u.f);
  printf("d = %f\n",u.d);
  v();
return 0;
}
int v(){
  union {
      float f;
      double d;
  }u;
  u.d = 10.0;
  u.f = 10.0;
  printf("d = %f\n",u.d);
  printf("f = %f\n",u.f);
return 0;
}

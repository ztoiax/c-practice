//数组指针转换
#include <stdio.h>
#include <string.h>
#define DAY 31
#define MON 12

int main(int argc, char *argv[]){
  char (*p)[DAY];
  char cline[MON][DAY];

  int iday,imon;
  int i;
//1:数组赋值
  for(imon = 0; imon < 12; imon++){
    for(iday = 0; iday < 10; iday++)
      cline[imon][iday] = iday + '0';
    cline[imon][iday] = '\0';
  }
//指针数组字符串打印
  printf("cline = %s\n",cline[0]);
  for(i = 0, p = cline; p < &cline[12]; i++, p++)
    printf("%d:p = %s\n",i, *p);

//2:指针赋值
  for(p = cline; p < &cline[12]; p++){
    char *dayp;
    for(dayp = *p; dayp < &(*p)[DAY]; dayp++)
      *dayp = '6';
  }

//1:数组打印
  printf("数组打印\n");
  for(imon = 0; imon < MON; imon++){
    for(iday = 0; iday < DAY; iday++)
      putchar(cline[imon][iday]);
    putchar('\n');
  }
  printf("指针打印\n");
//2:指针打印
  for(imon = 0; imon < MON; imon++){
    for(iday = 0; iday < DAY; iday++)
      putchar(*(*(cline + imon) + iday));
    putchar('\n');
  }
  return 0;
}

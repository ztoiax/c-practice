#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAXOP  100 // 操作数或运算符的最大长度
#define NUMBER '0'   // 标识找到一个数
 
int getop(char []);
 
int main(void) 
{ 
  int i;
  char c[1024];
  getop(c);
  for(i = 0;;i++)
    putchar(c[i]);
	return 0; 
}
 
#include <ctype.h>
 
int getch(void);
void ungetch(int);
 
int getop(char s[])
{
	int i, c;
 
	while ( (s[0] = c = getch()) == ' ' || c == '\t')
		;
 
	s[1] = '\0';
 
	if (!isdigit(c) && c != '.')
		return c;    // 不是数
 
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))  //收集整数部分
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch())) //收集小数部分
			;
 
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
 
#define BUFSIZE 100
 
char buf[BUFSIZE];   // 用于ungetch函数的缓冲区
int bufp = 0;   // buf 中下一个空闲的位置
 
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
 
void ungetch(int c)
{
	if (bufp > BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

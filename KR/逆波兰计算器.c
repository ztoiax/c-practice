#include <stdio.h>
#include <stdlib.h>
 
#define MAXOP  100 // 操作数或运算符的最大长度
#define NUMBER '0'   // 标识找到一个数
 
int getop(char []);
void push(double);
double pop(void);
 
int main(void) 
{ 
	int type;
	double op2, op3;
	char s[MAXOP];
 
	
	while ((type = getop(s)) != EOF)
	{
    printf("type = %c\n",type);
    printf("s = %s\n",s);
		switch(type)
		{
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			op3 = pop();
			if ((int)op2 == op2  && (int)op3 == op3 && op2 != 0 )
				push((int)op3%(int)op2);
			else
				printf("error----------\n");
			break;
	
		case '\n':
			printf("\t%.8g\n", pop());
			break;
 
		default:
			printf("error: unknown command %s\n", s);
			break;
 
		}
	}
 
 
 
	return 0; 
}
 
#define MAXVAL 100  // 栈val的最大深度
 
int sp = 0;   // 下一个空闲栈的位置
double val[MAXVAL];  // 值栈
 
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}
 
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else
	{
		printf("error:stack empty\n");
		return 0.0;
	}
 
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

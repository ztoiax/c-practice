#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF 1024
#define NUMBER 0

int getop(char cline[]);
void push (double d);
double pop(void);
int getch(void);
void ungetch(int c);
int main(int argc, char *argv[]){
  int itype;
  char cline[BUF];
  double op2;
  while((itype = getop(cline)) != EOF)
    switch(itype){
  case NUMBER:
      push(atof(cline));
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
      if(op2 == 0.0)
        printf("error: zero\n");
      push(pop() / op2);
      break;
  case '\n':
      printf("\t%.8g\n", pop());
      break;
    }
  return 0;
}
#define VAL 100
int sp = 0;
double val[VAL];

void push (double d){
  if(sp <= VAL)
    val[sp++] = d;
  else
    printf("error: val full\n");
}

double pop(void){
  if(sp > 0)
    return val[--sp];
  else{
    printf("error: stack 0\n");
    return 0.0;
  }
}
#include <ctype.h>
int getop(char cline[]){
  int i,c;
  while((cline[0] = c = getch()) == ' ' && c == '\t')
    continue;
  cline[1] = '\0';
  if(!isdigit(c))
    return c;
  i = 0;
  if(isdigit(c))
    while(isdigit(cline[++i] = c = getch()))
      continue;
  if(c == '.')
    while(isdigit(cline[++i] = c = getch()))
      continue;
  cline[i] = '\0';
  if(c != EOF)
    ungetch(c);
  return NUMBER;
}
#define SIZE 1000
int bufp = 0;
char buf[SIZE];

int getch(void){
 return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
  if(bufp >= SIZE)
    printf("error: buf full\n");
  else{
    buf[bufp++] = c;
  }
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define BUF 100

struct tnode {
  char *cword;
  int icount;
  struct tnode *left;
  struct tnode *right;
};

struct tnode *addtree(struct tnode *p, char *cw);
void treeprintf(struct tnode *p);
struct tnode *talloc(void);
char *my_strdup(char *cw);

int getword(char *cword, int ilim);
int getch(void);
void ungetch(int c);

int main(void){
  struct tnode *root;
  char cword[BUF];

  root = NULL;
  while(getword(cword,BUF) != EOF)
    if(isalpha(cword[0]))
      root = addtree(root,cword);
  treeprintf(root);
  return 0;
}

struct tnode *addtree(struct tnode *p, char *cw){
  int i;
  if(p == NULL){
    p = talloc();
    p->cword = my_strdup(cw);
    p->icount = 1;
    p->left = p->right = NULL;
  }
  else if((i = strcmp(cw, p->cword)) == 0)
    p->icount++;
  else if(i < 0)
    p->left = addtree(p->left, cw);
  else if(i > 0)
    p->right = addtree(p->right, cw);
  return p;
}

void treeprintf(struct tnode *p){
  if(p != NULL){
    printf("%4d %s\n",p->icount, p->cword);
    free(p->cword);
    treeprintf(p->left);
    treeprintf(p->right);
    free(p);
  }
}

struct tnode *talloc(void){
  return (struct tnode *)malloc(sizeof(struct tnode));
}

char *my_strdup(char *cw){
  char *p;

  p = (char *)malloc(strlen(cw)+1);
  if (p != NULL)
    strcpy(p,cw);
  return p;
}

int getword(char *cword, int ilim){
  int c;
  char *cw = cword;

  while(isspace(c = getch()))
    continue;
  if (c != EOF)
    *cw++ = c;
  if(!isalpha(c)){
    *cw = '\0';
    return c;
  }

  for(; --ilim; cw++)
    if(!isalnum(*cw = getch())){
      ungetch(*cw);
      break;
    }
  *cw = '\0';
  return cword[0];
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void){
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
  if(bufp >= BUFSIZE)
    printf("error:ungetch");
  else{
    buf[bufp++] = c;
  }
}

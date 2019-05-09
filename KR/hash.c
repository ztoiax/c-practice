#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define HASHSIZE 101
struct nlist {
    struct nlist *next;
    char *name;
    char *defn;//替换文本
};

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s){
  unsigned hashval;
  for(hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;
  return hashval % HASHSIZE; 
}

struct nlist *lookup(char *s){
  struct nlist *np;
  for(np = hashtab[hash(s)]; np != NULL; np++)
    if(strcmp(s,np->name) == 0)
      return np;
  return NULL;
}

struct nlist *install(char *name, char *defn){
  struct nlist *np;
  unsigned hashval;

  if((np = lookup(name)) == NULL){ //未找到
    np = (struct nlist *)malloc(sizeof *np);
    if(np == NULL || (np->name = strdup(name)) == NULL)
      return NULL;
    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
    printf("hashval = %d\n",hashval);
    printf("hashvalp = %p\n",hashtab[hashval]);
  }
  else//已存在
    free((void *)np->defn);
  if((np->defn = strdup(defn)) == NULL)
    return 0;
  return np;
}
int main(int argc, char *argv[]){
  struct nlist *np;
  char *name = "tz123";
  char *defn = "TZ";
  np = install(name, defn);
  printf("name = %s,defn = %s,next =%p\n",np->name, np->defn, np->next);
  free(np->name);
  free(np->defn);
  free(np);
  return 0;
}

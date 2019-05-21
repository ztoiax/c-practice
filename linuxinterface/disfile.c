#define _XOPEN_SOURCE 600 //get nftw() and S_IFSOCK
#include <ftw.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h> // geti realpath()
#include <string.h>
#include "color.h"

struct {
    unsigned i;
    unsigned r;
    unsigned d;
    unsigned l;
    unsigned c;
    unsigned p;
    unsigned b;
    unsigned s;
}count;

static int dirtree (const char *pathname, const struct stat *stbuf, int type, struct FTW *ftwb)
{
  switch (stbuf->st_mode & S_IFMT){
    case S_IFREG: printf("-");  count.r++;  break;
    case S_IFDIR: printf("d");  count.d++;  break;
    case S_IFCHR: printf("c");  count.c++;  break;
    case S_IFBLK: printf("b");  count.b++;  break;
    case S_IFLNK: printf("l");  count.l++;  break;
    case S_IFIFO: printf("p");  count.p++;  break;
    case S_IFSOCK: printf("s"); count.s++;  break;
    default: printf("?");  break;
  }
  count.i++;
  printf("    i-node:%7ld",stbuf->st_ino);
  printf("    size:%7ld",stbuf->st_size);
  printf("    %s\n", &pathname[ftwb->base]);
  return 0;
}

static int dirtree_d (const char *pathname, const struct stat *stbuf, int type, struct FTW *ftwb)
{
  count.i++;
  if (type == FTW_D){
      count.d++;
      printf("d");
      printf("    i-node:%7ld",stbuf->st_ino);
      printf("    \033[1;34m%s\033[0m\n", &pathname[ftwb->base]);
    }
  return 0;
}

static int dirtree_f (const char *pathname, const struct stat *stbuf, int type, struct FTW *ftwb)
{
  count.i++;
  if (type == FTW_F){
      count.r++;
      printf("-");
      printf("    i-node:%7ld",stbuf->st_ino);
      printf("    size:%7ld",stbuf->st_size);
      printf(L_GREEN"    %s\n"NONE, &pathname[ftwb->base]);
    }
  return 0;
}
static int dirtree_s (const char *pathname, const struct stat *stbuf, int type, struct FTW *ftwb)
{
  count.i++;
  if (type == FTW_SL){
      char buf[BUFSIZ];
      realpath(&pathname[ftwb->base],buf);
      count.l++;
      printf("l");
      printf("    i-node:%7ld",stbuf->st_ino);
      printf("    \033[1;32m%s\033[0m -> \033[1;33m%s\033[0m\n", &pathname[ftwb->base], buf);
    }
  return 0;
}

int main(int argc, char *argv[])
{
  count.i = count.d = count.r = count.l = count.c = count.p = count.b = count.s = 0;
  int flags = 0;
  if (argc > 1 && strcmp(argv[1],"-d") == 0){
      if (nftw((argc > 2 ? argv[2] : "."),dirtree_d, 10, flags) == -1){
          fprintf(stderr, "error: can't open dir \033[0;31m%s\033[0m\n",argv[2]);
      }
      printf("total %d dir \033[1;34m%d\033[0m(\033[1;33m%.2f%%\033[0m)\n", count.i, count.d, (float) count.d / count.i * 100);
  } else if (argc > 1 && strcmp(argv[1],"-s") == 0){
      flags |= FTW_PHYS; //不解链接
      if (nftw((argc > 2 ? argv[2] : "."),dirtree_s, 10, flags) == -1){
          fprintf(stderr, "error: can't open dir \033[0;31m%s\033[0m\n",argv[2]);
      }
      printf("total %d sylink \033[1;32m%d\033[0m(\033[1;33m%.2f%%\033[0m)\n", count.i, count.l, (float) count.l / count.i * 100);
  } else if (argc > 1 && strcmp(argv[1],"-f") == 0){
      if (nftw((argc > 2 ? argv[2] : "."),dirtree_f, 10, flags) == -1){
          fprintf(stderr, "error: can't open dir \033[0;31m%s\033[0m\n",argv[2]);
      }
      printf("total %d reg \033[1;33m%d\033[0m(\033[1;33m%.2f%%\033[0m)\n", count.i, count.r, (float) count.r / count.i * 100);
  } else{
      if (nftw((argc > 1 ? argv[1] : "."),dirtree, 10, flags) == -1){
          fprintf(stderr, "error: can't open dir \033[0;31m%s\033[0m\n",argv[1]);
      }
      float d, r, l, c, p, b, s;
      r = (float) count.r / count.i * 100;
      d = (float) count.d / count.i * 100;
      l = (float) count.l / count.i * 100;
      c = (float) count.c / count.i * 100;
      p = (float) count.p / count.i * 100;
      b = (float) count.b / count.i * 100;
      s = (float) count.s / count.i * 100;
      printf("total %d", count.i);
      printf(" dir "L_BLUE"%d"NONE, count.d);
      printf(L_YELLOW"(%.2f%%)"NONE, (float) count.d / count.i * 100);
      printf(" reg "L_GREEN"%d"NONE, count.r);
      printf(L_YELLOW"(%.2f%%)"NONE, (float) count.r / count.i * 100);
      printf(" sylink "L_CYAN"%d"NONE, count.l);
      printf(L_YELLOW"(%.2f%%)"NONE, (float) count.l / count.i * 100);
      printf(" block "L_PURPLE"%d"NONE, count.b);
      printf(L_YELLOW"(%.2f%%)"NONE, (float) count.b / count.i * 100);
      printf(" chr "L_PURPLE"%d"NONE, count.c);
      printf(L_YELLOW"(%.2f%%)"NONE, (float) count.c / count.i * 100);
      printf(" pipe "L_PURPLE"%d"NONE, count.p);
      printf(L_YELLOW"(%.2f%%)"NONE, (float) count.p / count.i * 100);
      printf(" soket "L_PURPLE"%d"NONE, count.s);
      printf(L_YELLOW"(%.2f%%)"NONE, (float) count.s / count.i * 100);
      putchar('\n');
  }

  return 0;
}

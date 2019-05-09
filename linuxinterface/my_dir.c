#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include "dir.h"

void fsize(char *);
void dirwalk(char *, void (*fun)(char *));

int main(int argc,char **argv)
{
  if(argc == 1)
    fsize(".");
  else
    while(--argc > 0)
      fsize(*++argv);
  return 0;
}

void fsize(char *name)
{
  struct stat stbuf;

  if (stat(name, &stbuf) == -1){
      fprintf(stderr,"error: fsize:can access %s\n",name);
      return;
  }
  if ((stbuf.st_mode & S_IFMT) == S_IFDIR){
      dirwalk(name, fsize);
  }

  printf("%8ld %s\n",stbuf.st_size, name);
}

#define MAX_PATH 1024
void dirwalk(char *dir, void(*fun)(char *))
{
   char name[MAX_PATH];
   Dirent *dp;
   Dir *dfd;

   if ((dfd = my_opendir(dir)) ==  NULL){
        fprintf(stderr,"my_opendir error %s\n",dir);
        return;
   }
   while ((dp = my_readdir(dfd)) != NULL){
      if (strcmp(dp->name, ".") == 0
          || strcmp(dp->name, "..") == 0)
          continue;

          sprintf(name, "%s/%s", dir, dp->name);
          (*fun)(name);
   }
   my_closedir(dfd);
}

Dir *my_opendir(char *dirname)
{
  int fd;
  struct stat stbuf;
  Dir *dp;

  if ((fd = open(dirname,O_RDONLY,0)) == -1
      || fstat(fd,&stbuf) == -1
      || (stbuf.st_mode & S_IFMT) != S_IFDIR
      || (dp = (Dir *) malloc(sizeof(Dir))) == NULL)
      return NULL;
  dp->fd = fd;
  return dp;
}

void my_closedir(Dir *dp)
{
  if(dp){
      close(dp->fd);
      free(dp);
  }
}

#include <sys/dir.h>
#define DIRSIZ 14

Dirent *my_readdir(Dir *dp)
{
  struct direct dirbuf;
  static Dirent d;
  long longd = sizeof(dirbuf);

  while(read(dp->fd, (char *) &dirbuf, longd) == longd){
      if(dirbuf.d_ino == 0)
         continue;
      d.ino = dirbuf.d_ino;
      strncpy(d.name, dirbuf.d_name, DIRSIZ);
      d.name[DIRSIZ] = '\0';
      return &d;
  }
      printf("read NULL\n");
  return NULL;
}

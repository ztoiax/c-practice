#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/dir.h>
#include <limits.h>

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

  stat(name, &stbuf);
  if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
      dirwalk(name, fsize);

  printf("%8ld %s\n",stbuf.st_size, name);
}

void dirwalk(char *dir, void(*fun)(char *))
{
   struct dirent *dp;
   DIR *dfd;

   if ((dfd = opendir(dir)) ==  NULL){
        fprintf(stderr,"opendir error %s\n",dir);
        return;
   }
   while ((dp = readdir(dfd)) != NULL){
      if (strcmp(dp->d_name, ".") == 0
          || strcmp(dp->d_name, "..") == 0)
          continue;

          (*fun)(dp->d_name);
   }
   closedir(dfd);
}

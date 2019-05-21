#include "tlpi_hdr.h"
#include "error_functions.c"
#include <dirent.h>
#include <fcntl.h>
#include <limits.h>

int main(int argc, char *argv[])
{
  int n = 0;
  int fd[1024];
  struct dirent *dp;
  DIR *dfd;


      printf("argv[1]:%s \n",argv[1]);
  if ((dfd = opendir(argv[1])) == NULL)
      printf("error: opendir\n");

  while ((dp = readdir(dfd)) != NULL){
      if((fd[n] = open(dp->d_name, O_RDONLY)) < 0){
          printf("error: open\n");
          exit(EXIT_FAILURE);
      }
      if (strcmp(dp->d_name, ".") == 0
          || strcmp(dp->d_name, "..") == 0)
          continue;
      printf("%d,file: %s\n", n++, dp->d_name);
  }
  closedir(dfd);
  return 0;
}

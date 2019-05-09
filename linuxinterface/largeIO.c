//大文件IO
#include <fcntl.h> 
#include <sys/stat.h>
#include "tlpi_hdr.h" 
#include "error_functions.c" 

#define _LARGEFILE64_SOURCE
int main(int argc, char *argv[])
{
  int fd;
  if ((fd = open("~/E/ISO镜像/Windows",O_RDONLY)) == -1) 
    fatal("open");
  if ((fd = open("~/E/ISO镜像/Windows",O_RDONLY | __O_LARGEFILE)) == -1)
    fatal("open1");
  return 0;
}

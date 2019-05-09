//5-2
//加入O_APPEND后在末端写,lseek无效
#include <string.h>
#include <fcntl.h>
#include "tlpi_hdr.h"
#include "error_functions.c"

int main(int argc, char *argv[]){
  int fd;
  char cline[] = "test\n";
  fd = open("test",O_WRONLY | O_APPEND);
  if (fd == -1)
    fatal("open");
  lseek(fd, 0L, SEEK_SET);
  write(fd, cline, strlen(cline));
  close(fd);
  return 0;
}

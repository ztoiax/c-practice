#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int flag;

  if (argc != 2){
      printf("please input file\n");
      exit(EXIT_FAILURE);
  }

  if ((flag = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0){
      printf("error: can't read file\n");
      exit(EXIT_FAILURE);
  }

  switch (flag | O_ACCMODE){
      case O_RDONLY:
        printf("read only");
        break;

      case O_WRONLY:
        printf("write only");
        break;

      case O_RDWR:
        printf("read write");
        break;

      default:
        printf("unknown access mode");
  }

  if (flag & O_APPEND)
      printf(",append");

  if (flag & O_NONBLOCK)
      printf(",NOONBLOCK");

  if (flag & O_SYNC)
      printf(",sync");

  putchar('\n');
  return 0;
}

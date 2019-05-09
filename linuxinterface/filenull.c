//文件空洞test
//文件竞争test
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define FLAG 0666

int main(int argc, char **argv){
  int fd;
  char *cline = "123\n";
  if(argc == 1)
    fprintf(stderr,"error: please input file\n");
  else{
      if((fd = open(*++argv,O_WRONLY,0)) == -1){
          printf("creat file: %s\n",*argv);
          sleep(5);
      }
      if(fd == -1){
          fd = creat(*argv,FLAG);
          printf("successful: %s,fd = %d\n", *argv, fd);
      }
      lseek(fd,10L,SEEK_END);
      if(write(fd, cline, strlen(cline)) != strlen(cline))
          fprintf(stderr,"error: write\n");
      close(fd);
  }
  return 0;
}

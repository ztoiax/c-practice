//清空,添加,删除环境变量,
#define _GNU_SOURCE
#include "tlpi_hdr.h"

extern char **environ;

int main(int argc, char *argv[]){
  char **envp;
  char *c;//getenv
  int i;//putenv

  clearenv();

  for (i = 1; i < argc; i++)
    putenv(argv[i]);

  setenv("a","123",0);
  setenv("b","123",0);

  unsetenv("b");

  for (envp = environ; *envp != NULL; envp++)
    puts(*envp);

  c = getenv("a");
  puts(c);
  return 0;
}

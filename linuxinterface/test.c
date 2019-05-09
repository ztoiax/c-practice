#include "tlpi_hdr.h"

int main(int argc, char *argv[])
{
  int lim;
  lim = sysconf(_SC_OPEN_MAX);
  lim = pathconf("~",_PC_PATH_MAX);
  printf("%d\n",lim);
  lim = pathconf("/home/tz",_PC_NAME_MAX);
  printf("%d\n",lim);
  return 0;
}

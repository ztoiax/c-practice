#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"
#include "error_functions.c"

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

int main(int argc, char *argv[]){
    int inFd, outFd, openFlags;
    mode_t filePerms;
    ssize_t numRead;
    char buf[BUF_SIZE];

    if (argc != 3 || strcmp(argv[1], "--help") == 0)
      usageErr("%s old-file new-file\n",argv[0]);
    
    /* Open input and output files */

    inFd = open(argv[1], O_RDONLY);
    if (inFd == -1)
      errExit("open file %s", argv[1]);

    openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
                S_IROTH |S_IWOTH;           /* rw-rw-rw */
    outFd = open(argv[2] ,openFlags, filePerms);
    if (outFd == -1)
      errExit("opening file %s", argv[2]);

    while ((numRead = read(inFd, buf, BUF_SIZE)) > 0)
      if (write(outFd, buf, numRead) != numRead)
        fatal("couldn't write whole buffer");
    if(numRead == -1)
      errExit("read");

    if(close(inFd) == -1)
      errExit("close input");
    if(close(outFd) == -1)
      errExit("close output");

    exit(EXIT_SUCCESS);
}

#include "file.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define PERMS 0666

FILES *my_fopen(char *name, char *mode){
  int fd;
  FILES *fp;

  if(*mode != 'r' && *mode != 'w' && *mode != 'a')
    return NULL;
  for(fp = _iob; fp <= _iob + OPEN_MAX; fp++)
    if((fp->flag & (_READ | _WRITE)) == 0)
      break;

  if(fp >= _iob + OPEN_MAX)
    return NULL;

  if(*mode == 'w')
    fd = creat(name, PERMS);
  else if(*mode == 'a'){
    if((fd = open(name,O_WRONLY,0)) == -1)
      fd = creat(name,PERMS);
    lseek(fd,0L,2);
  }else
    fd = open(name,O_RDONLY,0);

  if(fd == -1)
    return NULL;

  fp->fd = fd;
  fp->cnt = 0;
  fp->base = NULL;
  fp->flag = (*mode == 'r') ? _READ : _WRITE;
  return fp;
}

int _fillbuf(FILES *fp){
  int bufsize;
  if((fp->flag & (_READ|_EOF|_ERR)) != _READ)
    return EOF;
  bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZE;
  if(fp->base == NULL)
    if((fp->base = (char *)malloc(bufsize)) == NULL) //如果第二次进入,会内存泄露?
      return EOF;
  fp->ptr = fp->base;
  fp->cnt = read(fp->fd,fp->ptr,bufsize);

  if(--fp->cnt < 0){
    if(fp->cnt == -1)
      fp->flag |= _EOF;
    else
      fp->flag |= _ERR;
    
    fp->cnt = 0;
    return EOF;
  }
  return *fp->ptr++;
}

int _flushbuf(int x,FILES * fp){
  unsigned nc;
  int bufsize;

  if(fp < _iob || fp >= _iob + OPEN_MAX)
    return EOF;
  if((fp->flag & (_WRITE | _EOF | _ERR)) != _WRITE)
    return EOF;

  bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZE;
  if(fp->base == NULL){
    if((fp->base = (char*)malloc(bufsize)) == NULL){
      fp->flag |= _ERR;
      return EOF;
    }
  }else{
    nc = fp->ptr - fp->base;
    if((write(fp->fd, fp->base, nc) != nc)){
      fp->flag |= _ERR;
      return EOF;
    }
  }
  fp->ptr = fp->base;
  *fp->ptr++ = (char) x;
  fp->cnt = bufsize -1;
  return x;
}

int my_fflush(FILES *fp){
  int rc = 0;

  if(fp < _iob || fp >= _iob + OPEN_MAX)
    return EOF;
  if(fp->flag & _WRITE)
    rc = _flushbuf(0, fp);
  fp->ptr = fp->base;
  fp->cnt = (fp->flag & _UNBUF) ? 1 : BUFSIZE;
  return rc;
}

int my_fclose(FILES *fp){
  int rc;

  if((rc = my_fflush(fp) != EOF)){
    free(fp->base);
    fp->cnt = 0;
    fp->ptr = NULL;
    fp->flag &= ~(_READ | _WRITE);
  }
  return rc;
}

int my_fseek(FILES *fp, int offset, int origin){
  unsigned nc;
  long rc;

  if(fp->flag & _READ){
    if(origin == 1)
      offset -= fp->cnt;
    printf("fp->cnt = %d\n",fp->cnt);
    printf("offset = %d\n",offset);
    rc = lseek(fp->fd, offset, origin);
    fp->cnt = 0;
  }else if(fp->flag & _WRITE){
    if((nc = fp->ptr - fp->base) != 0)
      if(write(fp->fd, fp->base, nc) != nc)
        rc = -1;

    if(rc != -1)
      rc = lseek(fp->fd, offset, origin);
  }
  return (rc == -1) ? -1 : 0;
}

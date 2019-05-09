#undef NULL
#undef BUFSIZ
#undef EOF

#define NULL 0
#define BUFSIZE 1024
#define EOF (-1)
#define OPEN_MAX 20

typedef struct _iobuf {
  int cnt;
  char *ptr;
  char *base;
  int flag;
  int fd;
}FILES;

enum _flags {
      _READ  = 01,
      _WRITE = 02,
      _UNBUF = 04,
      _EOF   = 010,
      _ERR   = 020,
};

FILES _iob[OPEN_MAX] = {//stdin stdout stderr
      {0, (char *)0, (char *)0, _READ, 0},
      {0, (char *)0, (char *)0, _WRITE, 1},
      {0, (char *)0, (char *)0, _WRITE | _UNBUF, 2},
};

#define STDIN (&_iob[0])
#define STDOUT (&_iob[1])
#define STDERR (&_iob[2])


int _fillbuf(FILES *);
int _flushbuf(int, FILES *);

#define feof(p) ((p)->flag & _EOF != 0)
#define ferror(p) ((p)->flag & _ERR != 0)
#define fileno(p) ((p)->fd)

#define GETC(p) (--(p)->cnt >=0 \
            ? *(p)->ptr++ : _fillbuf(p))
#define PUTC(x,p) (--(p)->cnt >=0 \
            ? *(p)->ptr++ = (x) : _flushbuf((x), (p)))

#define GETCHAR() GETC(STDIN)
#define PUTCHAR(x) PUTC((x),STDOUT)

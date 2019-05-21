#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>  //get major() and minor()
#include <time.h>           //get ctime()

#define STR_SIZE sizeof("rwxrwxrwx")
#define FP_SPECIAL 1            /* Include set-user-ID, set-group-ID, and sticky
                                   bit information in returned string */

char *          /* Return ls(1)-style string for file permissions mask */
filePermStr(mode_t perm, int flags)
{
    static char str[STR_SIZE];

    /* If FP_SPECIAL was specified, we emulate the trickery of ls(1) in
       returning set-user-ID, set-group-ID, and sticky bit information in
       the user/group/other execute fields. This is made more complex by
       the fact that the case of the character displayed for this bits
       depends on whether the corresponding execute bit is on or off. */

    snprintf(str, STR_SIZE, "%c%c%c%c%c%c%c%c%c",
        (perm & S_IRUSR) ? 'r' : '-', (perm & S_IWUSR) ? 'w' : '-',
        (perm & S_IXUSR) ?
            (((perm & S_ISUID) && (flags & FP_SPECIAL)) ? 's' : 'x') :
            (((perm & S_ISUID) && (flags & FP_SPECIAL)) ? 'S' : '-'),
        (perm & S_IRGRP) ? 'r' : '-', (perm & S_IWGRP) ? 'w' : '-',
        (perm & S_IXGRP) ?
            (((perm & S_ISGID) && (flags & FP_SPECIAL)) ? 's' : 'x') :
            (((perm & S_ISGID) && (flags & FP_SPECIAL)) ? 'S' : '-'),
        (perm & S_IROTH) ? 'r' : '-', (perm & S_IWOTH) ? 'w' : '-',
        (perm & S_IXOTH) ?
            (((perm & S_ISVTX) && (flags & FP_SPECIAL)) ? 't' : 'x') :
            (((perm & S_ISVTX) && (flags & FP_SPECIAL)) ? 'T' : '-'));

    return str;
}

static void displayStatInfo(const struct stat *f)
{
  printf("File  type :                ");

  switch (f->st_mode & S_IFMT){
    case S_IFREG: printf("regular file\n");     break;
    case S_IFDIR: printf("directory file\n");   break;
    case S_IFCHR: printf("character device\n"); break;
    case S_IFBLK: printf("block device\n");     break;
    case S_IFLNK: printf("symlolic link\n");    break;
    case S_IFIFO: printf("FIFO OR pipe\n");     break;
    case S_IFSOCK: printf("socket \n");         break;
  }

  printf("Device inode:               major=%d minor=%d\n", major(f->st_dev), minor(f->st_dev));

  printf("I-node number:              %lu\n",f->st_ino);

  printf("Mode:                       %o (%s)\n", f->st_mode, filePermStr(f->st_mode, 0));

  if (f->st_mode & (S_ISUID | S_ISGID | S_ISVTX))
      printf("special bit set:           %s%s%s\n",
            (f->st_mode & S_ISUID) ? "set-UID" : "",
            (f->st_mode & S_ISGID) ? "set-GID" : "",
            (f->st_mode & S_ISVTX) ? "sticky"  : "");

  printf("Number of hard link:        %lu\n", f->st_nlink);

  printf("Ownership:                  UID = %d  GID=%d\n", f->st_uid, f->st_gid);

  if (S_ISCHR(f->st_mode) || S_ISBLK(f->st_mode))
      printf("Device number (st_rev): major=%u  minor=%u\n", major(f->st_rdev), minor(f->st_rdev));

  printf("File size:                  %ld bytes\n", f->st_size);
  printf("Optimal I/O block size:     %ld bytes\n", f->st_blksize);
  printf("512B blocks allocated:      %ld\n", f->st_blocks);
  printf("Last file access            %s", ctime(&f->st_atime));
  printf("Last file modification:     %s", ctime(&f->st_mtime));
  printf("Last status change          %s", ctime(&f->st_ctime));
  putchar('\n');
}

int main(int argc, char **argv)
{
  struct stat file;
  if (argc < 2){
      fprintf(stderr, "error: please intput file\n");
      exit(EXIT_FAILURE);
  }

  while (--argc != 0){
      if ((lstat(*++argv, &file)) == -1){
          fprintf(stderr, "error: %s is not file\n", *argv);
          exit(EXIT_FAILURE);
      }
      printf("FILE: %s\n", *argv);
      displayStatInfo(&file);
  }
  return 0;
}

#define NAME_MAX 14

typedef struct {
      long ino;
      char name[NAME_MAX+1]; /*文件吗加结束符'\0'*/
}Dirent;

typedef struct {
      int fd;
      Dirent d;
}Dir;

Dir *my_opendir(char *dirname);
Dirent *my_readdir(Dir *dfd);
void my_closedir(Dir *dfd);


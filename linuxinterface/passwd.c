#include "tlpi_hdr.h"
#include <pwd.h>
#include <shadow.h>
#include <limits.h>
#include <crypt.h>
#include <unistd.h>

#define _XOPEN_SOURCE

int my_getline(char cline[], int ilimit){
  int i, c;
  for(i = 0; i < ilimit-1 && (c = getchar()) != EOF && c != '\n'; i++){
    cline[i] = c;
    if(c == '\n')
      cline[i]++;
  }
  cline[i] = '\0';
  return i;
}

int main(void)
{
  struct passwd *pwd;
  struct spwd *spwd;
  long lname;
  char *uname, *passwd, *cry, *p;
  size_t len;
  Boolean ok;

  lname = sysconf(_SC_LOGIN_NAME_MAX);
  uname = (char *) malloc(lname);
  if (!my_getline(uname, lname))
    exit(EXIT_FAILURE);

  len = strlen(uname);
  pwd = getpwnam(uname);
  if (pwd == NULL)
    printf("error: getpwname\n");
  spwd = getspnam(uname);
  if (spwd == NULL)
    printf("error: getspname\n");
  if (spwd != NULL)
    pwd->pw_passwd = spwd->sp_pwdp;

  passwd = getpass("Passwd: ");
  cry = crypt(passwd, pwd->pw_passwd);

  for (p = passwd; *p != '\0';)
    *p++='\0';

  if (cry == NULL)
    printf("error: crypt\n");

  ok = strcmp(cry, pwd->pw_passwd) == 0;
  if (!ok){
    printf("error: incorrect password\n");
    exit(EXIT_FAILURE);
  }

  printf("successfully !\n");
  free(uname);
  return 0;
}

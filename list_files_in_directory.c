#include <stdio.h>

int main(void)
{
  DIR           *d;
  struct dirent *dir;
  d = opendir("./Teatro_Infantil/");

  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      printf("%s\n", dir->d_name);
    }

    (void) closedir(d);
  }
  else
  {
    perror ("Couldn't open the directory");
    exit(0);
  }

  return 0;
}

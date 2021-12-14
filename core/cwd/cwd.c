#include <stdio.h>

char *getcwd(char *buf, size_t size);
int main()
{
  char cwd[999];
  printf("%s\n", getcwd(cwd, sizeof(cwd)));
}

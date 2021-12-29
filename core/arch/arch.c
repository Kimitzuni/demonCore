#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <sys/utsname.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[])
{
  struct utsname buffer;
  char *p;
  long ver[16];
  int i=0;
  
  errno = 0;
  if (uname(&buffer) != 0) {
    perror("os");
    exit(EXIT_FAILURE);
  }
  
  // gnu Linux Kernel x86_64 
  printf("%s ", buffer.machine);

  printf("\n");
  p = buffer.release;
  
  while (*p) {
    if (isdigit(*p)) {
      ver[i] = strtol(p, &p, 10);
      i++;
    } else {
      p++;
    }
  }
}

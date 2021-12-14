
#include <stdio.h>
#include <sys/sysinfo.h>

int main(int argc, char *argv[])
{
  printf("%d\n",get_nprocs());
    return 0;
}


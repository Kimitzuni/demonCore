#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define VERSION "0.1.5"

int main(int argc, char *argv[100])
{
  char c;
  FILE *readfile;

  if (argc == 1)
  {
    printf("fileout: no filename provided\n");
  } else if (argc == 2) {
    
    if(strcmp(argv[1], "--help") == 0 ||
       strcmp(argv[1], "-h") == 0)
    {
      help();
      exit(0);

    }
    readfile = fopen(argv[1], "r");

    if (readfile == NULL)
    {
      printf("fileout: %s does not exist\n", argv[1]);
      exit(0);
    }

    c = fgetc(readfile);
    while (c != EOF)
    {
        printf("%c", c);
        c = fgetc(readfile);
    }
    
    fclose(readfile);
    return 0;
  }
}
int help()
{
  printf("\ndemonCore Fileout v%s\n", VERSION);
  printf("\n");

  printf("Standard Usage:\n");
  printf("\033[1;92mfileout \033[1;93m<filename> \033[1;95m[OPTIONS]\033[0m\n");
  printf("\n");

  printf("This program is licensed under the GNU General Public License v2\n");
  printf("Contribute at <https://github.com/Kimitzuni/demonCore>\n");
  exit(0);
}

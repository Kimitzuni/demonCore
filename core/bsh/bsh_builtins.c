#include <stdio.h>
#include <stdlib.h>

int bsh_cd(char** args);
int bsh_help();
int bsh_exit();
int bsh_license();
int bsh_welcome();
int bsh_versionInfo();

char *builtin_str[] = {
  "cd",
  "help",
  "licenseinfo",
  "exit"
};

int (*builtin_func[]) (char **) = {
  &bsh_cd,
  &bsh_help,
  &bsh_license,
  &bsh_exit
};

int bsh_num_builtins() {
  return sizeof(builtin_str) / sizeof(char*);
}

int bsh_cd(char** args)
{
    if (args[1] == NULL) {
      #ifdef SHOW_CD_NOARGS_TEXT
      printf("bsh: 'cd' was not given any arguments, going to home directory\n");
      #endif

      chdir(getenv("HOME"));
    } else {
      if (chdir(args[1]) != 0) {
        perror("bsh");
      }
    }
    return 1;
}

int bsh_help()
{
  printf("\n");
  printf(".................................\n");
  printf("A Painfully POSIX Compliant Shell\n");
  printf("\n");


  #ifndef COLOURS
  printf("help        ........... Display this help\n");
  printf("licenseinfo ........... Display License Info\n");
  printf("\n");

  printf("bsh Source Code <https://github.com/Kimitzuni/bsh>\n");
  printf("Pull Requests <https://github.com/Kimitzuni/bsh/pulls>\n");
  printf("Submit Patches to <mailto:rtw@null.net>\n\n");
  #else
  printf("\033[1;92mhelp\033[0m        ........... Display this help\n");
  printf("\033[1;92mlicenseinfo\033[0m ........... Display License Info\n");
  printf("\n");

  printf("bsh Source Code <\033[1;93mhttps://github.com/Kimitzuni/bsh\033[0m>\n");
  printf("Pull Requests <\033[1;93mhttps://github.com/Kimitzuni/bsh/pulls\033[0m>\n");
  printf("Submit Patches to <\033[1;96mmailto:rtw@null.net\033[0m>\n\n");
  #endif

  return 1;
}

int bsh_versionInfo()
{
  printf("bsh Version %s\n", VERSION_NUMBER);
}

int bsh_license()
{
	printf("bsh is licensed under the GNU General Public License v2\n\n");
	printf("This license can be found in the LICENSE file\n");

	return 1;
}

int bsh_welcome()
{
	printf("Welcome to 'bsh' - The Painfully POSIX Compliant Shell\n\n");
	return 1;
}

int bsh_exit()
{
    return 0;
}

/*
 *		demonCore userview
 * 	A replacement for the GNU 'whoami'
 * 		     utility
 */

#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <pwd.h>
#include <string.h>
#define VERSION "0.51"

int i = 1;
int main(int argc, char *argv[])
{
	while(true)
	{
		if (argc == 1)
		{
			struct passwd *p = getpwuid(getuid());
			printf("%s\n", p->pw_name);
			break;
		}
		else
		{
			if (strcmp(argv[i], "--help") == 0 ||
				strcmp(argv[i], "-h") == 0)
			{
				help_info();
			}

			if (strcmp(argv[i], "--fluent") == 0 ||
				strcmp(argv[i], "-f") == 0)
			{
				fluentOutput();
			}

			break;
		}
	}
}


int help_info()
{
	printf("demonCore UserView Utility Version %s\n", VERSION);
	printf("A Replacement for the GNU 'whoami' program\n\n");

	printf("--help -h        Display this help text\n");
	printf("--fluent -f      Display the output in a fluent way\n\n");

	printf("This software is licensed under the GNU General Public License v2\n");
}

int fluentOutput()
{
	struct passwd *p = getpwuid(getuid());
	char hostname[256];
	int ret;
	ret = gethostname(&hostname[0], 256);

	if (ret == -1) {
		perror("unable to get hostname");
	}

	printf("\033[1;95m%s\033[0m on \033[1;96m%s\033[0m\n", p->pw_name, hostname);
}

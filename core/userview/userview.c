/*
 *		demonCore userview
 * 	A replacement for the GNU 'whoami'
 * 		     utility
 */

#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <pwd.h>
#define VERSION "0.5"

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
		else if (argc == 2)
		{
			help_info();
			break;
		}
	}
}


int help_info()
{
	printf("demonCore UserView Utility");
	printf(" Version %s\n", VERSION);
	printf("A Replacement for the GNU 'whoami' program\n\n");

	printf("This software is licensed under the\n");
	printf("GNU General Public License v2\n");
}

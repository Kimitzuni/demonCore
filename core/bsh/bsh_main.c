#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "bsh_vars.h"

#include "bsh_readline.c"
#include "bsh_builtins.c"
#include "bsh_exec.c"


char *getcwd(char *buf, size_t size);

int main(int argc, char **argv)
{

	#ifdef SHOW_WELCOME
	bsh_welcome();
	#endif
	bsh_loop();
	return EXIT_SUCCESS;
}

void bsh_loop()
{
	char *line;
	char **args;
	int status;
	int cmdnum;

	cmdnum = 1;
	do {
	    char cwd[999];

		#ifdef COLOURS
		char PROMPT[] = "\033[1;95mbsh-";
		#else
		char PROMPT[] = "bsh-";
		#endif

		// Provide the actual prompt on the line
		#ifdef COLOURS
	        printf("%s%s \033[0m[\033[1;96m%s\033[0m]$ ", PROMPT, VERSION_NUMBER, getcwd(cwd, sizeof(cwd)));
		#else
			printf("%s%s [%s]$ ", PROMPT, VERSION_NUMBER, getcwd(cwd, sizeof(cwd)));
		#endif
		line = bsh_readline();
		args = bsh_split(line);
		status = bsh_run(args, cmdnum);

		cmdnum++;

		free(line);
		free(args);
	} while (status);
}

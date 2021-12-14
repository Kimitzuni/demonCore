#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		displayHelp(argc, argv);
		exit(0);
	} else {
		output(argc, argv);
	}
}

int output(int argc, char *argv[])
{
	int i = 1;
	while (i)
	{
		for (i=1; i<argc; i++)
		{
			printf("%s ",argv[i]);
		}
		printf("\n");
	}
}

int displayHelp(int argc, char *argv[])
{
	printf("No - A Replacement for the 'yes' Utility\n");
	printf("version 0.1\n");
	printf("Usage: %s [STRING]\n", argv[0]);
}

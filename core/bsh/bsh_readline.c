/*
 * Basic SHell / bsh READLINE Library
 * -------------------------------------------------
 * Created by rtw (Rebecca T. White/rtiannew@gmail.com)
 *
 * This is a part of the bsh Code, and as such is licensed
 * under the GNU General Public License v2
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define BSH_RL_BUFFERSIZE 1024
#define BSH_TOK_BUFFERSIZE 64
#define BSH_TOK_DELIM " \t\r\n\a"

char *bsh_readline(void)
{
    int bufsize = BSH_RL_BUFFERSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    if (!buffer)
    {
      fprintf(stderr, "bsh: Allocation Error\n");
      exit(EXIT_FAILURE);
    }

    while (1) {
      c = getchar();

      if (c == EOF || c == '\n') {
        buffer[position] = '\0';
        return buffer;
      } else {
        buffer[position] = c;
      }

      position++;

      if (position >= bufsize) {
        bufsize += BSH_RL_BUFFERSIZE;
        buffer = realloc(buffer, bufsize);
        if (!buffer) {
          fprintf(stderr, "bsh: Allocation Error\n");
          exit(EXIT_FAILURE);
        }
      }

    }
}

char **bsh_split(char *line)
{
  int buffersize = BSH_TOK_BUFFERSIZE, position = 0;
  char **tokens = malloc(buffersize * sizeof(char*));
  char *token;

  if (!tokens) {
    fprintf(stderr, "bsh: Allocation Error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, BSH_TOK_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= buffersize) {
      buffersize += BSH_TOK_BUFFERSIZE;
      tokens = realloc(tokens, buffersize * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, "bsh: Allocation Error\n");
        exit(EXIT_FAILURE);
      }
    }
    token = strtok(NULL, BSH_TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}

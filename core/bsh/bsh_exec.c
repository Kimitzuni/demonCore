#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int bsh_launch(char **args, int cmdnum)
{
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
    if (execvp(args[0], args) == -1) {
      printf("[%d] bsh: %s: not found\n", cmdnum, args[0]);
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    perror(args[0]);
  } else {
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
  return 1;
}

int bsh_run(char **args, int cmdnum)
{
  int i;

  if (args[0] == NULL) {
    return 1;
  }

  for (i = 0; i < bsh_num_builtins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }
  return bsh_launch(args, cmdnum);
}

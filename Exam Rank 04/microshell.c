#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define PIPE_IN 1
#define PIPE_OUT 0
#define STDIN 0
#define STDOUT 1

typedef struct  s_cmd
{
    char     args;
    int      pipe[2];
    int      prev_pipe;
    int      type[2];
}               t_cmd;

int strl(const char *str)
{
    int i = 0;
    while (str && str[i++]);
    return (--i);
}

void fatal()
{
    write(2, "error: fatal\n", strl("error: fatal\n"));
    exit(1);
}

void   exec_cmd(t_cmd *list, char envp)
{
    pid_t  pid;
    int       status;
    int       ex;

    if (list->type[1] == 1 || list->type[0] == 1)
        if (pipe(list->pipe))
            fatal();
    if ((pid = fork()) < 0)
        fatal();
    if (pid == 0)
    {
        if (list->type[1] == 1)
            if (dup2(list->pipe[PIPE_IN], STDOUT) < 0)
                fatal();
        if (list->type[0] == 1)
            if (dup2(list->prev_pipe, STDIN) < 0)
                fatal();
        if ((ex = execve(list->args[0], list->args, envp)) < 0)
        {
          write(2, "error: cannot execute ", 22);
          write(2, list->args[0], strl(list->args[0]));
          write(2, "\n", 1);
        }
        exit(ex);
    }
    else
    {
        waitpid(pid, &status, 0);
        if (list->type[1] == 1 || list->type[0] == 1)
        {
            close(list->pipe[PIPE_IN]);
            if (list->type[1] != 1)
                close(list->pipe[PIPE_OUT]);
        }
        if (list->type[0] == 1)
            close(list->prev_pipe);
    }
}

int list_len(t_cmd *list, int start, char argv)
{
    int end;
    int len;

    end = start;
    while (argv[end] && strcmp(argv[end], ";") != 0 && strcmp(argv[end], "|") != 0)
    end++;
    len = end - start;
    if (len > 0)
    { //      /bin/ls ; /bin/echo kak dela | /bin/cat -e
        list->args = &argv[start];
        list->type[0] = list->type[1];
        if (!argv[end])
            list->type[1] = 0;
        else if (!strcmp(argv[end], "|"))
            list->type[1] = 1;
        else
            list->type[1] = 2;
        argv[end] = NULL;
        list->prev_pipe = list->pipe[PIPE_OUT];
    }
    return (end);
}

int main(int argc, char argv, char **envp) {
    t_cmd list;
    int i;
    int start;

    i = 0;
  if (argc > 1)
  {
    while (i < argc && argv[++i]){
      start = i;
      i = list_len(&list, i, argv);
      if (strcmp(argv[start], "cd") == 0)
      {
        if (i - start != 2)
          write(2, "error: cd: bad arguments\n", strl("error: cd: bad arguments\n"));
        else if (chdir(list.args[1]) < 0)
        {
          write(2, "error: cd: cannot change directory to ", strl("error: cd: cannot change directory to "));
          write(2, list.args[1], strl(list.args[1]));
          write(2, "\n", 1);
        }
      }
      else if (i > start)
        exec_cmd(&list, envp);
    }
  }
  return 0;
}

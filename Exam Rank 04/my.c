#include <unistd.h>
#include <stdlib.h>
#include <string.h>

size_t ft_strlen(char *s)
{
    size_t i = 0;

    while (s[i])
        ++i;
    return(i);
}

void error(char *s, char *path)
{
    write(2, s, ft_strlen(s));
    if (path)
    {
        write(2, path, ft_strlen(path));
        write(2, "\n", 1);
    }
    exit(1);
}

char **sub(char **argv, int start, int end)
{
    char **res;
    int i = 0;

    res = malloc(sizeof(char *) * (start - end + 1));
    if (res == NULL)
        return(NULL);
    while (start < end)
        res[i++] = argv[start++];
    res[i] = NULL;
    return(res);
}

int main(int argc, char **argv, char **env)
{
    int i, post, start, end;
    int fd[2], fd_in;
    pid_t pid;
    char **av;

    i = 1;
    while (i < argc)
    {
        post = start = end = i;
        while (post < start && strcmp(argv[post], ";"))
            ++post;
        fd_in = 0;
        while (start < post)
        {
            end = start;
            while (end < post && strcmp(argv[end], "|"))
                ++end;
            av = sub(argv, start, end);
            if (av == NULL)
                error("error: fatal\n", NULL);
            if (pipe(fd) == -1)
                error("error: fatal\n", NULL);
            pid = fork();
            if (pid == -1)
                error("error: fatal\n", NULL);
            else if (pid == 0)
            {
                if (dup2(fd_in, 0) == -1)
                    error("error: fatal\n", NULL);
                if (end < post && dup2(fd[1], 1) == -1)
                    error("error: fatal\n", NULL);
                close(fd_in);
                close(fd[0]);
                close(fd[1]);
            }
        }
    }
    return (0);
}

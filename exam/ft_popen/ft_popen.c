# include <unistd.h>
# include <stdlib.h>
#include <sys/wait.h>


int ft_popen(const char *file, const char *argv[] , char type)
{
    int pipefd[2];

    if (type != 'r' && type != 'w')
        return -1;
    
    if (pipe(pipefd))
        return (-1);
    pid_t pid = fork ();
    if (pid < 0)
        return (-1);
    if (pid == 0)
    {
        if (type == 'w')
        {
            if (dup2(pipefd[0],0) == -1)
            {
                close (pipefd[0]);
                close (pipefd[1]);
                exit (1);
            }
        }
        else if (type == 'r')
        {
            if (dup2(pipefd[1],1) == -1)
            {
                close (pipefd[0]);
                close (pipefd[1]);
                exit (1);
            } 
        }
        close (pipefd[0]);
        close (pipefd[1]);
        execvp(file, argv);
        exit (1);
    }
    else
    {
        if (type == 'r')
        {
            close(pipefd[1]);
            return pipefd[0];
        }
        else
        {
            close(pipefd[0]);
            return pipefd[1];
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int count_word(char *str) {
    int i = 0;

    while (str[i])
    {
        while (str[i] **)
        i++;    
    }
}

char** ft_split() {
    
}

./picohell "/bin" "grep txt" "ls -l"

int doLast() {

}

int doArgs(char *cmd) {
    int pipefd[2];

    if (pipe(pipefd) == -1)
        return (-1);

    pid_t pid = fork();
    
    if (pid < 0)
        return -1;
    if (pid == 0)
    {
        if (dup2(pipefd[1], 1) == -1)
        {
            close(pipefd[0]);
            close(pipefd[1]);
            return -1;
        }
        close(pipefd[0]);
        close(pipefd[1]);
        execve(,,NULL);
    }
    else
    {
        if (dup2(pipefd[0], 0) == -1)
        {
            close(pipefd[0]);
            close(pipefd[1]);
            return -1;
        }
        close(pipefd[0]);
        close(pipefd[1]);
        waitpid(pid, NULL, 0);
    }
    return (0);
}

int main(int argc, char *argv[]) {
    
    return (0);
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int count_words(const char *str)
{
    int i = 0;
    int word = 0;

    while (str[i] == ' ')
        i++;

    while (str[i]) {
        word++;
        while (str[i] && str[i] != ' ')
            i++;
        while (str[i] == ' ')
            i++;
    }

    return word;
}

char *create_string(char **str)
{
    int i = 0;

    char *start = *str;
    while ((*str)[i] && (*str)[i] != ' ')
        i++;

    char *new = malloc (sizeof(char) * (i + 1));
    for (int j = 0; j < i; j++)
        new[j] = start[j];
    new[i] = '\0';
    *str += i;
    return new;
}

char **ft_split(char *str) {
    int len = count_words(str);

    char **arr = malloc(sizeof(char*) * (len + 1));
    int i = 0;
    while (i < len)
    {
        while (*str == ' ')
            str++;
        arr[i] = create_string(&str);
        i++;
    }
    arr[i] = NULL;
    return arr;
}

void doLast(char *argv) {
    int pid = fork();
    if (pid < 0)
        return ;
    if (pid == 0)
    {
        
        char **com = ft_split(argv);
        execve(com[0], com, NULL);   
    }
    else
    {
        waitpid(pid, NULL, 0);
    }
}

void doArgs(char *argv) {
    int pipefd[2];

    if (pipe(pipefd) == -1)
        return ;
    int pid = fork();
    if (pid < 0)
        return ;
    if (pid == 0)
    {
        
        char **com = ft_split(argv);
        close(pipefd[0]);
        dup2(pipefd[1], 1);
        close(pipefd[1]);
        execve(com[0], com, NULL);   
        // child
    }
    else
    {
        close(pipefd[1]);
        dup2(pipefd[0], 0);
        close(pipefd[0]);
        waitpid(pid, NULL, 0);
        // parent
    }
}

int main(int argc, char *argv[]) {
    int i = 1;
    while (i < argc - 1){
        doArgs(argv[i]);
        i++;
    }
    doLast(argv[i]);
    return (0);
}
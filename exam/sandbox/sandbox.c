# include <sys/wait.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <stdlib.h>

static pid_t test_pid = -1;

int sandbox(void (*f)(void), unsigned int timeout, bool verbose, int fd)
{
    pid_t pid = fork();

    if (pid < 0)
        return (-1);
    if (pid == 0)
    {
        alarm(timeout);
        f();
        exit (0);
    }
    else
    {
        test_pid  = pid;
        write(fd, &test_pid, sizeof(test_pid));
        printf("%u\n", test_pid);
        int status;
        int exit_code;

        if (waitpid(pid, &status, WUNTRACED) == -1)
            return -1;

        if (status == 0)
        {
            if (verbose)
                printf("Nice Function!\n");
            return (0);
        }

        if (WIFEXITED(status))
        {
            exit_code = WEXITSTATUS(status);
            if (verbose)
                printf("Bad function exited with code %d\n", exit);
        }
        else if (WIFSIGNALED(status))
        {
            exit_code = WTERMSIG(status);
            if (exit_code == SIGALRM)
            {
                if (verbose)
                    printf("Bad function (timeout in %u seconds)\n", timeout);
                return (1);
            }
            else
            {
                if (verbose)
                    printf("Bad function (signal: %s)\n", strsignal(exit));
            }
        }
        else if (WIFSTOPPED(status))
        {
            exit_code = WSTOPSIG(status);
            kill(pid, SIGKILL);
            waitpid(pid, NULL, 0);
            if (verbose)
                printf("Bad function (signal: %s)\n", strsignal(exit));
        }
        return (1);
    }
}

void test(void) {
    while (1)
        ;

    // char * test = NULL;
    // test[1] = 'a';
}

int main(void) {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid2 = fork();
    if (pid2 == 0) {
        // Child process runs sandbox and sends test_pid to parent
        close(pipefd[0]); // close read end

        // Run sandbox (this will set the static test_pid in child)
        sandbox(&test, 10, 1, pipefd[1]);

        // Write test_pid to parent (if set)
        close(pipefd[1]);

        exit(0);
    }

    // Parent process
    close(pipefd[1]); // close write end
    pid_t received_pid = -1;
    read(pipefd[0], &received_pid, sizeof(received_pid));
    close(pipefd[0]);

    printf("test_pid in parent: %u\n", received_pid);
    if (received_pid != -1)
        kill(received_pid, SIGSTOP);
    waitpid(pid2, NULL, 0);
    return 0;
}



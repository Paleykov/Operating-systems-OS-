#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <sys/wait.h>

// Да се напише програма на С, която получава като параметър команда с опции и 
// аргумeнти. При успешното ѝ изпълнение, извежда на стандартния изход кода на завършане.

int main(argc,argv)
int argc;char* argv[];
{
    char* arguments[argc];
    for(int i = 0; i < argc-1; ++i)
    {
        arguments[i] = argv[i+1];
    }
    arguments[argc-1] = NULL;

    pid_t pid = fork();
    int status = 0;

    if(pid == -1)
    {
        printf("error forking");
        exit(1);
    }
    else if(pid == 0)
    {
        execvp(argv[1], arguments);
        printf("failed to execute the command in child");
        exit(1);
    }
    else
    {
        wait(&status);
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            printf("You successfully ran the command: %s and the code is: %d\n", argv[1], status);
        } else {
            printf("Failed to run the command: %s and the code is: %d\n", argv[1], status);
            exit(1);
        }
    }
}
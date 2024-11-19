#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <sys/wait.h>

// Да се напише програма на С, която получава като параметър команда (без параметри) 
// и при успешното ѝ изпълнение, извежда на стандартния изход името на командата.

int main(argc,argv)
int argc; char* argv[];
{
    pid_t pid = fork();
    int status = 0;

    char* arguments[argc];
    for(int i = 0; i < argc-1; ++i)
    {
        arguments[i] = argv[i+1];
    }
    arguments[argc-1] = NULL;

    if(pid == -1)
    {
        printf("couldn't fork");
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
            printf("You successfully ran the command: %s\n", argv[1]);
        } else {
            printf("Failed to run the command: %s\n", argv[1]);
            exit(1);
        }
    }
}
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
// #include <sys/wait.h>

// Да се напише програма на С, която получава като параметри три команди (ще го направя за n) (без параметри), изпълнява ги последователно, 
// като изчаква края на всяка и извежда на стандартния изход номера на завършилия процес, както и неговия код на завършване

int main(argc,argv)
int argc; char* argv[];
{
    for(int i = 1; i<argc; ++i)
    {
        int status;
        pid_t pid = fork();
        pid_t child;

        if(pid == -1)
        {
            printf("failed to fork\n");
            exit(1);
        }
        else if(pid == 0)
        {
            execlp(argv[i], argv[i], NULL);
            printf("failed to execute %s\n", argv[i]);
            exit(1);
        } 
        else
        {
            child = wait(&status);
            if (WIFEXITED(status) && WEXITSTATUS(status) == 0) 
            {
                printf("You successfully ran the command: %s with pid: %d and the code is: %d\n", argv[i], child, status);
            } else 
            {
                printf("Failed to run the command: %s with pid: %d and code: %d\n", argv[i], child, status);
                exit(1);
            }
        }
    }
}
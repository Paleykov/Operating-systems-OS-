#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
// #include <sys/wait.h>

// Да се напише програма на C, която получава като параметри от командния ред две команди 
// (без параметри). Изпълнява първата. Ако тя е завършила успешно изпълнява втората. Ако не, завършва с код -1.

int main(argc,argv)
int argc; char* argv[];
{
    pid_t pid = fork();
    int status;

    if(pid == -1)
    {
        printf("error forking");
        exit(1);
    }else if(pid == 0){
        execlp(argv[1], argv[1], NULL);
        printf("error executing the first command\n");
        exit(1);
    }else{
        wait(&status);
        if(WIFEXITED(status) && WEXITSTATUS(status) == 0)
        {
            execlp(argv[2], argv[2], NULL);
            printf("successfully finished the first command but failed the second");
            exit(-1);
        }else{
            exit(-1);
        }
    }
}
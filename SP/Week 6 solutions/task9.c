#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
//#include <sys/wait.h>

// Да се напише програма на C, която получава като командни параметри 
// две команди (без параметри). Изпълнява ги едновременно и извежда на стандартния 
// изход номера на процеса на първата завършила успешно. Ако нито една не завърши успешно извежда -1

int main(argc,argv)
int argc; char* argv[];
{
    pid_t pid1;
    pid_t pid2;
    int status;

    if((pid1 = fork()) == -1)
    {
        printf("error forking");
        exit(1);
    }else if(pid1 == 0){
        execlp(argv[1], argv[1], NULL);
        printf("error executing the first command\n");
        exit(1);
    }
    
    if((pid2 = fork()) == -1)
    {
        printf("error forking");
        exit(1);
    }else if(pid2 == 0){
        execlp(argv[2], argv[2], NULL);
        printf("error executing the second command\n");
        exit(1);
    }
    
    pid_t result = wait(&status);
    if(WIFEXITED(status) && WEXITSTATUS(status) == 0)
    {
        printf("the first command was with a pid %d\n", result);
    }else{
        printf("error -1"); 
        exit(1);
    }
}
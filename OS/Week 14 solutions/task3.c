#include <fcntl.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>

// Да се напише програма на C, която получава като параметър в командния ред  
// една команда и при успешното й изпълнение извежда на стандартния изход името на командата. 

int main(int argc, char *argv[])
{
    pid_t num = fork();
    int status;

    if (num == -1)
    {
        printf("error");
        exit(1);
    }
    else if(num == 0)
    {
        execlp(argv[1], argv[1], 0);
    }
    else 
    {
        wait (&status);
        if(status == 0)
            printf("argv[1]");
    }
}
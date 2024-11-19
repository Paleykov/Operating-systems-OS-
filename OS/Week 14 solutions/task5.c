#include <fcntl.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>

// Да се напише програма на C, която получава като параметри в командния 
// ред 2 команди (без параметри). Програмата реализира конструкцията: команда1 && команда2

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
        execlp(argv[2], argv[2], 0);
    }
}
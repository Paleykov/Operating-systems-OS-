#include <fcntl.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>

// Да се напише програма на C, която отпечатва  PID-a на процесите родител и дете. 
// След което в  детето с достатъчно дълъг цикъл без печат  
// да се задържи детето, за да приключи своята работа процеса родител.
int main(int argc, char *argv[])
{
    pid_t num = fork();

    if (num == -1)
    {
        printf("error");
        exit(1);
    }
    else if(num == 0)
    {
        printf("child --> pid of the child is %d and of the parent is %d", getpid(), getppid());
        for(int i = 0; i < 6969696969; ++i);
    }
    else 
    {
        printf("parent --> pid of the parent is %d and of the parent's parent is %d", getpid(), getppid());
    }
}
#include <fcntl.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>

// Да се напише програма на C, която създава файл abc в текущата директория и го 
// отваря за писане. Създава 2 процеса, които пишат в него hello.

int main(int argc, char *argv[])
{
    int fd1 = open("abc", O_CREAT|O_TRUNC|O_WRONLY, 0744);
    if(fd1 == -1)
    {
        printf ("couldn't open file");
        exit(1);
    }

    pid_t status;
    pid_t num = fork();

    if(num == -1)
    {
        printf ("couldn't fork properly");
        exit(1);
    } 
    else if (num == 0)
    {
        pid_t num2 = fork();
        if(num2 == -1)
        {
            printf ("couldn't fork properly");
            exit(1);
        }
        else if (num2 == 0)
        {
            if ( (write(fd1, "hello", 5)) <= 0)
            {
                printf ("couldn't write in file");
                exit(1);
            }
        }
        else
        {
            if ( (write(fd1, "hello", 5)) <= 0)
            {
                printf ("couldn't write in file");
                exit(1);
            }
        }
    }
    else
    {
        wait(&status);
    }

    close(fd1);
}
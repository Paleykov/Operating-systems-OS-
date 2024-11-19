#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

// Да се напише програма на C, която реализира командата cat >> f1

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("\n Expected 3 arguments");
        exit(1);
    }

    int fd1 = open (argv[3], O_WRONLY|O_CREAT|O_APPEND, 0644);
    if(fd1 == -1)
    {
        print("\n Error creating file");
        exit(1);
    }

    char buffer[1024];
    int nbytes = 0;

    while((nbytes = read(0, buffer, 1024)) > 0)
    {
        if (write(fd1, buffer, nbytes) <= 0)
        {
            printf("\n couldn't write \n");
            exit(1);
        }
    }

    close(fd1);
}
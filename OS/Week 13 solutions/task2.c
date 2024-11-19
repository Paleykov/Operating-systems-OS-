#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

// Да се напише програма на C, която реализира командата tee f1

int main (int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("\n expected 2 arguments");
        exit(1);
    }

    int fd1 = open (argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if(fd1 == -1)
    {
        print("\n Error creating file");
        exit(1);
    }

    char buffer[1024];
    int nbytes =  0;

    while ((nbytes = read (0, buffer, 1024))>0)
    {
        write (1, buffer, nbytes);
        write (fd1, buffer, nbytes);
    }

    close(fd1);
}
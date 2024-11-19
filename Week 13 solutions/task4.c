#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

// Да се напише програма на C, която реализира командата cat [f1...]
// Допускаме, че са n на брой файла

int n;

int main(int argc, char *argv[])
{
    if (argc < n+1)
    {
        printf("\n expected %d numbers", (n+1));
        exit(1);
    }

    int fd[n];
    char buffer[1024];
    int nbytes=0;

    for (int i = 0; i < argc; ++i)
    {
        if ((fd[i] = open(argv[i], O_RDONLY)) == -1)
        {
            printf("\n couldn't open file $s", argv[i]);
            exit(1);
        }

        while ((nbytes = read (fd[i], buffer, 1024)) > 0)
        {
            write(1, buffer, nbytes);
        } 
    }

    for (int i = 0; i < argc; ++i)
    close(fd[i]);
}
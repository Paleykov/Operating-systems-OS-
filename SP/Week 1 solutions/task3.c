#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

// Да се напише програма на C, която реализира командата cat >> файл

int main(int argc, char* argv[])
{
    int fd1 = open(argv[2], O_WRONLY, O_APPEND, O_CREAT, 0644);
    if(fd1 == -1)
    {
        printf("error opening file");
        exit(1);
    }

    char buffer[512];
    int nbytes = 0;
    char size = 512;

    while((nbytes = read(0, buffer, size)) > 0)
    {
        write(fd1, buffer, nbytes);
    }

    close(fd1);
}
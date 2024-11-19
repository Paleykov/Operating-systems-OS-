#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Записват се във файл 25 байта извън програмата. Програмата чете от файла по 10 байта  и отпечатава какво връща състемния примитив read

int main(argc,argv)
int argc; char* argv[];
{
    int fd1 = open(argv[1], O_RDONLY);
    if(fd1==-1)
    {
        printf("error opening file");
        exit(1);
    }

    char buffer[10];
    int nbytes = 0;

    while((nbytes = read(argv[1], buffer, 10)) > 0)
    {
        write(1, buffer, nbytes);
    }

    close(fd1);
}
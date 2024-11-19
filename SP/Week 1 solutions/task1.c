#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

// Да се напише програма на C, която реализира командата cp файл1 файл2

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("\n expected 3 arguments: cp f1 f2");
        exit(1);
    }

    int fd1 = open (argv[1], O_RDONLY);
    if(fd1 == -1)
    {
        printf("\n couldn't open file %s\n", argv[1]);
        exit(1);
    }

    int fd2 = open (argv[2], O_WRONLY, O_TRUNC, O_CREAT, 0644);
    if(fd2 == -1)
    {
        printf("\n couldn't open file %s\n", argv[2]);
        exit(1);
    }

    char buffer[1024];
    int sizeRead = 1000;
    int alreadyRead = read(fd1, buffer, sizeRead);

    while(alreadyRead > 0)
    {
        write(fd2, buffer, alreadyRead);
        alreadyRead = read(fd1, buffer, sizeRead);
    }
    
    close(fd1);
    close(fd2);
    return 0;
}
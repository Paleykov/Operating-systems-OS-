#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Напишете програма на Си, която отваря файл за четене, дублира дескритора, 
// последователно чете от двата дескриптора и извежда прочетеното на екрана. 
// Затваря оригиналния дексриптор и продължава за чете от дублирания.

int main(argc,argv)
int argc; char* argv[];
{
    int fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        printf("error opening file");
        exit(1);
    }

    int fd2 = dup(fd);

    char buffer1[10];
    char buffer2[10];

    read(fd, buffer1, 10);
    read(fd2, buffer2, 10);

    write(1,buffer1,10);
    write(1,"\n", 1);

    write(1,buffer2,10);
    write(1,"\n", 1);

    close(fd);

    read(fd2, buffer2, 10);
    write(1,buffer2,10);
    write(1,"\n", 1);

    close(fd2);
}
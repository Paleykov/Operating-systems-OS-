#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(argc,argv)
int argc; char* argv[];
{
    int fd1 = open("fff", O_RDONLY);
    if(fd1==-1)
    {
        printf("error opening file");
        exit(1);
    }
    int fd2 = open("fff", O_WRONLY);
    if(fd2==-1)
    {
        printf("error opening file");
        exit(1);
    }
    int fd3 = open("fff", O_RDWR);
    if(fd3==-1)
    {
        printf("error opening file");
        exit(1);
    }

    write(fd3, "Hello", 5);
    write(fd2, "worlds", 6);

    char buffer[10];
    read(fd1, buffer, 6); write(1, buffer, 6);

    close(fd2);

    write(fd3, "oops", 4);

    char buffer2[10];
    read(fd1, buffer2, 6); write(1, buffer2, 6);

    close(fd1); close(fd3);
}
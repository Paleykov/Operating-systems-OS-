#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(argc, argv)
int argc; char* argv[];
{
    int fd = open(argv[2], O_RDONLY);
    if(fd == -1)
    {
        printf("error opening file");
        exit(1);
    }
    
    int number = atoi(argv[1]);
    
    lseek(fd, number, SEEK_SET);
    char buffer[512];
    int nbytes = 0;
    while((nbytes = read(fd, buffer, 512)) > 0)
    {
        write(1, buffer, nbytes);
    }

    close(fd);
}
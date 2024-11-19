#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Напишете програма на Си, която получава като аргумент  два файла. 
// Чете от първия файл и извежда във втория чрез механизма на пренасочване 
// на стандартния вход и изход.

int main(argc, argv)
int argc; char* argv[];
{
    int fd1 = open(argv[1], O_RDONLY);
    if(fd1 == -1)
    {
        printf("error opening file");
        exit(1);
    }

    int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_APPEND | O_TRUNC, 0644);
    if(fd2 == -1)
    {
        printf("error opening file");
        close(fd1);
        exit(1);
    }

    int zam_vhod = dup(0);
    close(0);
    int fd1_0 = dup(fd1);

    int zam_izhod = dup(1);
    close(1);
    int fd2_1 = dup(fd2);

    char buffer[512];
    int nbytes = 0;
    while((nbytes = read(0, buffer, 512)) > 0)
    {
        write(1, buffer, nbytes);
    }

    close(0);
    dup(zam_vhod);

    close(1);
    dup(zam_izhod);
}
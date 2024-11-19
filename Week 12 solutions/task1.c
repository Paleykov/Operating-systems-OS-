#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

// Да се напише програма на C, която реализира командата  cp f1 f2

int main(int argc,char *argv[])
{
    if (argc != 3)
    {
        printf("\n Proper usage: cp from to");
        exit(1);
    }

    int f1d = open(argv[1], O_RDONLY);
    if(f1d == -1)
    {
        printf("\n couldn't open file %s\n", argv[1]);
        exit(1);
    }

    int f2d = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if(f2d == -1)
    {
        printf("\n couldn't open file %s\n", argv[2]);
        exit(1);
    }

    char buff[512];
    int size = 512;
    int sizeChanging = read(f1d, buff, size);

    while(sizeChanging > 0)
    {
        write(f2d, buff, sizeChanging);
        sizeChanging = read(f1d, buff, size);
    }

    close(f1d);
    close(f2d);
}

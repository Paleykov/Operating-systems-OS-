#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

// Записва се във файл 25 байта. 
// Чете от него по 10 байта и отпечатва какво връща read.

int main(int argc,char *argv[])
{
    if (argc != 1)
    {
        printf("\n expected 1 argument only");
        exit(1);
    }

    int f1d = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0744);
    if(f1d == -1)
    {
        printf("\n couldn't open file %s\n", argv[0]);
        exit(1);
    }
    
    char *buff[25]="1234567890123456789012345";
    int f1dwr = write(f1d, buff, 25);

    if(f1dwr == -1)
    {
        printf("\n couldn't write in file %s\n", argv[0]);
        exit(1);
    }

    close(f1d);

    int f2d = open(argv[0], O_RDONLY);
    if(f2d == -1)
    {
        printf("\n couldn't open file %s\n", argv[0]);
        exit(1);
    }

    char buff[10];
    int readSize = read(f2d, buff, 10);

    while(readSize > 0)
    {
        write(1, buff, 10);
        readSize = read(f2d, buff, 10);
    }

    close(f2d);
}
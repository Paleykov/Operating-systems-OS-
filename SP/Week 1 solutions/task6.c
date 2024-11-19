#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

// Да се напише програма на C, която реализира командата head -10l файл

int main(int argc, char* argv[])
{
    int fd1 = open(argv[2], O_RDONLY);
    if(fd1==-1)
    {
        printf("error opening file");
        exit(1);
    }

    for(int i = 0; i<10; ++i)
    {
        char buffer[512];
        int nbytes = 0;

        int currSymbol = 0;
        char symbol;

        while ((nbytes = read(fd1, symbol, 1)) > 0 && symbol != "\n")
        {
            buffer[currSymbol] = symbol;
            ++currSymbol;
        }

        printf("$s", buffer);
    }
    
    close(fd1);
}
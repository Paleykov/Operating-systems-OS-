#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Файлът се подава като параметър в командния ред.

char buffer[16];
int main(argc,argv)
int argc; char* argv[];
{
    int aa = open(argv[1], O_RDONLY);
    if(aa == -1)
    {
        printf("error opening file");
        exit(1);
    }

    for(int i = 5; i > 0; --i)
    {
        read(aa, buffer, i);
        printf("%s \n", buffer);
    }

    close(aa);
    return 0;
}
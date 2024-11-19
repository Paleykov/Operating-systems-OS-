#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Горната задача, като вместо printf използва системен примитив write  и извежда на стандартния изход.

char buffer[16];
int main(argc,argv)
int argc; char* argv[];
{
    int aa = open("aa", O_RDONLY);
    if(aa == -1)
    {
        printf("error opening file");
        exit(1);
    }

    for(int i = 5; i > 0; --i)
    {
        read(aa, buffer, i);
        write(1, buffer, i);
    }

    close(aa);
    return 0;
}
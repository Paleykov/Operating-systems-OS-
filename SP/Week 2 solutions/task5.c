#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Първата задача, като преди всяко read се слага системен примитив lseek.
// lseek(fd, 0 , 0)
// lseek( fd, 3, 0)
// lseek( fd, 3, SEEK_CUR)
// lseek( fd, -3, SEEK_END) и други варианти


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
        // lseek(aa, 0 , 0);
        // lseek(aa, 3, 0);
        // lseek(aa, 3, SEEK_CUR);
        // lseek(aa, -3, SEEK_END);
        read(aa, buffer, i);
        printf("%s \n", buffer);
    }

    close(aa);
    return 0;
}
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// В задача 2 се създава файл с име f1 и се пранасочва стандартния изход в него :
//    •	чрез open
//    •	чрез системен примитив dup


int main(argc, argv)
int argc; char* argv[];
{
    int fd1 = open("f1", O_WRONLY | O_TRUNC | O_CREAT | O_APPEND, 0644);
    if(fd1 == -1)
    {
        printf("error opening file");
        exit(1);
    }

    int k = dup(1); // otiva nqkude != 1
    close(1);
    int j = dup(fd1); // otiva v j=1

    for(int i = 0; i < 10; ++i)
    {
        write(1, "EXAMPLE", sizeof("EXAMPLE"));
    }

    close(1); // j izchezva
    dup(k); // k = 1 otiva v 1
}
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// В зад 5 след EXAMPLE се пранасочва стандартния изход в подадения 
// като параметър файл и числата от 1 до 10 излизат във файла. 
// След това се възстановява стандартния изход и HELLO  отново е на екрана.

int main(argc, argv)
int argc; char* argv[];
{
    for(int i = 0; i<10; ++i)
    {
        write(1, "EXAMPLE", 7);
    }

    int fd1 = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT | O_APPEND, 0644);
    
    if(fd1 == -1)
    {
        printf("error opening file");
        exit(1);
    }

    int k = dup(1); // k stava 1 na random mqsto
    close(1); // 1 se osvobojdava
    int j = dup(fd1); // fd1 stava 1

    for(int i = 0; i<10; ++i)
    {
        char boi[2];
        sprintf(boi, "%d", i);
        write(1, boi, sizeof(boi));
    }

    close(j);
    dup(k);

    for(int i = 0; i<10; ++i)
    {
        write(1, "HELLO", 5);
    }
}
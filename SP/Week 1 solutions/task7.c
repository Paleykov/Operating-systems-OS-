#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

// Да се напише програма на C, която реализира командата cut -cm-n файл (m и n да се четат от входа)

int  main(int argc, char* argv[])
{
    int m,n;
    scanf("%d %d", &m, &n);

    int fd1;
    if((fd1 = open(argv[2], O_RDONLY)) == -1)
    {
        printf("error opening file");
        exit(1);
    }

    char buffer[1024];
    int counter = 0;
    int nbytes = 0;

    while((nbytes = read(fd1, buffer, 1024)) > 0)
    {
        for(int i = 0; i < nbytes; ++i)
        {
            if(buffer[i] == "\n")
            {
                counter = 0;
                write(1, "\n", 1);
            }
            else if(counter >= m && counter <= n)
            {
                write(1, buffer[i], 1);
                ++counter;
            }
            else
            {
                ++counter;
            }
        }
    }

    close(fd1);
}
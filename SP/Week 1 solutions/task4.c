#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

// Да се напише програма на C, която реализира командата tee [файл1 файл2 ..... файлN ]

int main(int argc, char* argv[])
{
    char buffer[1024];
    char nbytes = 0;
    int fd[argc-1];

    for(int i = 1; i<=argc-1; ++i)
    {
        fd[i] = open (argv[i], O_WRONLY, O_APPEND, O_CREAT, 0644);
        if(fd[i] == -1)
        {
            printf("error opening file");
            // trqbva cikul za zatvarqne na vsichki failove predi tova ama ne mi se zanimava
            exit(1);
        }  
    }

    while((nbytes = read(0, buffer, 1024)) > 0)
    {
        for(int i = 1; i<=argc-1; ++i)
        {
            write(fd[i], buffer, nbytes);
        }
        write(1, buffer, nbytes);
    }

    for(int i = 1; i<=argc-1; ++i)
    close(fd[i]);
}
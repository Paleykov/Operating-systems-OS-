#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// В цикъла се изпълнява команда, която брои буквите във файла aa.

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

        pid_t pid = fork();
        if (pid == -1) 
        {
            perror("fork failed");
            close(aa);
            exit(1);
        }
        else if (pid == 0) 
        {
            execlp("wc", "wc", "-c", "aa", NULL);
            perror("execlp failed");
            exit(1);
        }
    }

    close(aa);
    return 0;
}
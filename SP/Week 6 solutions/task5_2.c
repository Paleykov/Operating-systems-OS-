#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
// #include <sys/wait.h>

// В зад 4 пренасочвате изхода на детето във втория файл. В общи действия на двата процеса 
// се записват hello3 на стандартния изход и hello4 във втория файл:
// •	без wait в родителя

int main(argc,argv)
int argc; char* argv[];
{
    int fd1 = open(argv[1], O_WRONLY | O_APPEND | O_TRUNC | O_CREAT, 0644);
    if(fd1 == -1)
    {
        printf("error opening file");
        exit(1);
    }

    int fd2 = open(argv[2], O_WRONLY | O_APPEND | O_TRUNC | O_CREAT, 0644);
    if(fd2 == -1)
    {
        printf("error opening file");
        close(fd2);
        exit(1);
    }

    pid_t pid = fork();

    if(pid == -1)
    {
        printf("error forking");
        close(fd1); close(fd2);
        exit(1);
    } else if (pid == 0) {
        int k = dup(1);
        close(1);
        int j = dup(fd2);

        write(1, "Hello2", 6);
    } else {
        write(fd1, "Hello1", 6);
    }

    write(1, "Hello3", 6);
    write(fd2, "Hello4", 6);

    close(fd1);
    close(fd2);
}
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
// #include <sys/wait.h>

// Да се напише програма на С, която получава като параметър име на файл. 
// Отваря подадения файл за писане (ако не съществува, го създава, в противен случай го занулява), 
// създава 2 процеса и двата процеса пишат символния низ Hello във файла.
// •	чрез единствения дескриптор

int main(argc, argv)
int argc; char* argv[];
{
    int fd1 = open(argv[1], O_WRONLY | O_APPEND | O_CREAT | O_TRUNC, 0644);
    if(fd1 == -1)
    {
        printf("error opening file");
        exit(1);
    }

    pid_t pid = fork();
    if(pid == -1)
    {
        printf("error forking");
        exit(1);
    }
    else if(pid == 0)
    {
        write(fd1, "Hello from child \n", 5); 
    }
    else
    {
        write(fd1, "Hello from parent \n", 5);
    }

    close(fd1);
}
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
// #include <sys/wait.h>

// Да се напише програма на С, която получава като параметри две имена на файлове. 
// Отваря първия файл за писане (ако не съществува, го създава, в противен случай го занулява), 
// създава 2 процеса. Родителят пише hello1, а детето – hello2 във първия файл. 

int main(argc,argv)
int argc; char* argv[];
{
    int fd1 = open(argv[1], O_WRONLY | O_APPEND | O_TRUNC | O_CREAT, 0644);
    if(fd1 == -1)
    {
        printf("error opening file");
        exit(1);
    }

    pid_t pid = fork();

    if(pid == -1)
    {
        printf("error forking");
        close(fd1);
        exit(1);
    } else if (pid == 0) {
        write(fd1, "Hello2", 6);
    } else {
        write(fd1, "Hello1", 6);
    }

    close(fd1);
}
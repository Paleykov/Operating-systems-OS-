#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
// #include <sys/wait.h>

// Да се напише програма на С, която получава като параметри имена на два файла. 
// В зад 6 пренасочва изхода на процеса дете във втория файл 
// (ако не съществува, го създава, в противен случай добавя в него)

int main(argc,argv)
int argc; char* argv[];
{
    int fd1 = open(argv[1], O_WRONLY | O_APPEND | O_CREAT| O_TRUNC, 0644);
    if(fd1 == -1)
    {
        printf("error opening file");
        exit(1);
    }

    int fd2 = open(argv[1], O_WRONLY | O_APPEND | O_CREAT| O_TRUNC, 0644);
    if(fd2 == -1)
    {
        printf("error opening file");
        close(fd1);
        exit(1);
    }

    pid_t pid = fork();
    int status;

    if(pid == -1)
    {
        printf("error forking");
        exit(1);
    } else if(pid == 0) {
        write(fd1, "Hello", 5);
    } else {
        wait(&status);
        char buffer[5];
        read(fd1, buffer, 5);

        int k = dup(1); // k stava 1 i otiva na random mqsto
        close(1);
        int j = dup(fd2); // j stava fd2 i otiva na mqsto 1

        int counter = 0;
        for(int i = 0; i<5; ++i)
        {
            write(1, buffer[i], 1);
            if(counter == 2)
            {
                counter = 0;
                write(1," ", 1);
            }
            else
            ++counter;
        }

        close(j); // 1 se osvobojdava
        dup(k); // k=1 otiva na 1
    }

    close(fd1);
}
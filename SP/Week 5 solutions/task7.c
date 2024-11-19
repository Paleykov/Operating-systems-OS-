#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
// #include <sys/wait.h>

// Да се напише програма на С, която получава като параметър име на файл. 
// Създава процес син, който записва стринга Hello във файла (ако не съществува, 
// го създава, в противен случай го занулява), след което процеса родител прочита 
// записаното във файла съдържание и го извежда на стандартния изход, добавяйки 
// по един интервал между всеки два символа.

int main(argc,argv)
int argc; char* argv[];
{
    int fd1 = open(argv[1], O_RDWR | O_APPEND | O_CREAT| O_TRUNC, 0644);
    if(fd1 == -1)
    {
        printf("error opening file");
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
    }

    close(fd1);
}
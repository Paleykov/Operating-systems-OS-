#include <fcntl.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>

// Да се напише програма на C, която получава като параметри от команден ред две команди (без параметри) 
// и име на файл в текущата директория. Ако файлът не съществува, го създава. 
// Програмата изпълнява командите последователно, по реда на подаването им. 
// Ако първата команда завърши успешно, програмата добавя нейното име към съдържанието на файла, 
// подаден като команден параметър. Ако командата завърши неуспешно, програмата уведомява потребителя чрез подходящо съобщение.

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("expected 3 arguments");
        exit(1);
    }   

    int status;

    int fd1;
    if((fd1 = open (argv[3], O_CREAT|O_WRONLY|O_APPEND, 0744)) == -1)
    {
        printf("error opening file");
        exit(1);
    }

    pid_t num1 = fork();

    if(num1 == -1)
    {
        printf("error forking");
        exit(1);
    }
    else if (num1 == 0)
    {
        execlp(argv[1], argv[1], 0);
    }
    else
    {
        wait(&status);

        if(status == 0)
            write(fd1, argv[1], sizeof(argv[1]));
        else
            printf("\n The first command failed");

            pid_t num2 = fork();
            if(num2 == -1)
            {
                printf("error forking");
                exit(1);
            }
            else if (num2 == 0)
            {
                execlp(argv[2], argv[2], 0);
            }
            else
            {
                wait(&status);
            }
    }
}
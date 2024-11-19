#include <fcntl.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>

// Да се напише програма на C, която получава като 
// параметър в командния ред една команда 
// (изпълним файл) и списък с параметри за нея. 
// Поражда процес дете и сменя образа му с командата. 
// В родителя изчаква наследника да приключи и 
// извежда номера му и кода на завършване.

int main(int argc, char *argv[])
{
    pid_t num = fork();
    int status;

    if (num == -1)
    {
        printf("error");
        exit(1);
    }
    else if(num == 0)
    {
        execvp(argv[1], &argv[1]);
    }
    else 
    {
        wait (&status);
        printf("The status is %d and the parent pid is $d", status, getpid());
    }
}
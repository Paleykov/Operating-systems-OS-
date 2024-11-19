#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
// #include <sys/wait.h>

// Да се напише програма на C, която изпълнява последователно подадените 
// ѝ като параметри команди, като реализира следната функционалност постъпково:
// o	main cmd1 ... cmdN Изпълнява всяка от командите в отделен дъщерен процес.
// o	... при което се запазва броя на изпълнените команди, които са дали грешка и броя на завършилите успешно.

int main(int argc, char *argv[])
{
    int status;
    int counter = 0;

    for(int i = 1; i < argc; ++i)
    {
        pid_t num = fork();

        if(num == -1)
        {
            printf("couldn't fork");
            exit(1);
        }
        else if(num == 0)
        {
            printf("the current process is %s:\n", argv[i]);
            execlp(argv[i], argv[i], NULL);
            exit(1);
        }
        else 
        {
            wait(&status);
            if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
                ++counter;
        }
    }

    printf("\n The number of failed processes is %d and the number of passed processes is %d", (argc - 1 - counter), counter);
}
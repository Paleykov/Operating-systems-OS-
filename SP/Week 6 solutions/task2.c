#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
// #include <sys/wait.h>

// Да се пусне един fork() и само в детския процес още един fork(). 
// За всеки генериран процес се отпечатва pid-а на процеса/getpid()/ и 
// pid-a на родителския процес/getppid()/. - 4 процеса

int main(argc,argv)
int argc; char* argv[];
{
    pid_t pid1 = fork();
    int status;

    if(pid1 == -1)
    {
        printf("error forking");
        exit(1);
    } else if(pid1 == 0) {
        int curr_pid = getpid();
        int parent_curr_pid = getppid();
        printf("I am the child in pid1 and this is my pid: %d and this is the pid of my parent: %d \n", curr_pid, parent_curr_pid);

            pid_t pid2 = fork();
            if(pid2 == -1)
            {
                printf("error forking");
                exit(1);
            } else if(pid2 == 0) {
                int curr_pid = getpid();
                int parent_curr_pid = getppid();
                printf("I am the child in pid2 and this is my pid: %d and this is the pid of my parent: %d \n", curr_pid, parent_curr_pid);
            } else {
                wait(&status);
                int curr_pid = getpid();
                int parent_curr_pid = getppid();
                printf("I am the parent in pid2 and this is my pid: %d and this is the pid of my parent: %d \n", curr_pid, parent_curr_pid);
            }
    } else {
        wait(&status);
        int curr_pid = getpid();
        int parent_curr_pid = getppid();
        printf("I am the parent in pid1 and this is my pid: %d and this is the pid of my parent: %d \n", curr_pid, parent_curr_pid);
    }

}
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(argc, argv)
int argc; char* argv[];
{
    int fd1 = open(argv[1], O_RDONLY);
    if(fd1 == -1)
    {
        print("error opening file");
        exit(1);
    }

    int fd2 = open(argv[2], O_WRONLY, O_TRUNC, O_CREAT, O_APPEND, 0644);
    if(fd2 == -1)
    {
        print("error opening file");
        exit(1);
    }

    int status = 0;
    int pid = fork(); 

    if(pid != 0)
    {
        wait(&status);
        execlp("wc", "wc", "-l", argv[2], 0);
    }
    else
    {
        char line[512];
        char character;
        int counter = 0;

        for(int i = 0; i<=60; ++i)
        {
            while(read(fd1, character, 1) > 0)
            {
                line[counter]=character;

                if(character == "\n")
                {
                    if(line[counter-1] == "$")
                    {
                        write(1, line, 512);
                    }
                    else
                    {
                        for(int k = 0; k <= counter; ++k)
                        {
                            if(line[k] >= "0" || line[k] <= "9")
                            write(argv[2], k, 1);
                            write(argv[2], "\n", 1);
                        }
                    }
                    counter = 0;
                    line[0] = "\0";
                }
                else
                {
                    ++counter;
                }
            }
        }
    }
}
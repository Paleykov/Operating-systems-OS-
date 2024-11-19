#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

//  Да се напише програма на C, която реализира командата cut -cm-n f1
//  (m и n да се четат от входа)

int main (int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("\n expected 3 arguments");
        exit(1);
    }

    int m; int n;
    scanf("%d %d", &m, &n);

    int fd1;
    if ((fd1 = open(argv[3], O_RDONLY)) == -1)
    {
        printf("\n couldn't open file");
        exit(1);
    }

    char buffer[1024];
    int nbytes;
    int counter = 0;

    while((nbytes = read (fd1, buffer, 1024)) > 0)
    {   
        for(int i = 0; i<nbytes; ++i)
        {
            if(buffer[i] == '\n')
            {
                counter = 0;
                write(1, '/n', 1);
            }
            else
            {
                if(counter >= m && counter <= n)
                {
                    if ((write(1, &buffer[i], 1)) == -1)
                    {
                        printf("\n error writing the output");
                        exit(1);
                    }
                }
            }
            ++counter;
        }
    }
}

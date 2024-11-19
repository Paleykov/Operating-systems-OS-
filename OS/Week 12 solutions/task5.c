#include <fcntl.h>
#include <unistd.h>

//	Да се напише програма на C, която реализира командата wc f1

int main(int argc,char *argv[])
{   
    if (argc != 2)
    {
        printf("\n expected 2 arguments only");
        exit(1);
    }

    int f1d = open(argv[1], O_RDONLY);
    if(f1d == -1)
    {
        printf("\n couldn't open file %s\n", argv[0]);
        exit(1);
    }

    int lines = 0;
    int words = 0;
    int bytes = 0;

    char buff;
    int reading = read (f1d, buff, 1);

    while(reading > 0)
    {
        bytes++;

        if(buff == ' ' || buff == '/n')
        words++;

        if(buff == '/n')
        lines++;

        read (f1d, buff, 1);
    }

    close(f1d);
}
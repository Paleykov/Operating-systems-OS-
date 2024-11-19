#include <fcntl.h>
#include <unistd.h>

// Чете последователност от символи от файл, чието име е подадено като първи параметър. 
// Извежда ги на стандартния изход. Първите 3 символа от всеки ред добавя след края на файл, 
// чието име е подадено като втори параметър.

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

    int f2d = open(argv[2], O_WRONLY|O_CREAT|O_APPEND, 0755);
    if(f2d == -1)
    {
        printf("\n couldn't open file %s\n", argv[1]);
        exit(1);
    }

    char buff;
    int reading = read(f1d, buff, 1);
    int counter = 1;
    
    while(reading > 0)
    {
        write(1, buff, 1);

        if(buff != '/n')
        {
            if(counter < 3)
            {
                write(f2d, buff, 1);
                counter++;
            }
        }
        else
        {
            counter=0;
        }

        reading = read(f1d, buff, 1);
    }

    close(f1d);
    close(f2d);
}

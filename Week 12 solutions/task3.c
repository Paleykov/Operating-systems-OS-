#include <fcntl.h>
#include <unistd.h>

// Чете последователност от символи от стандартния вход. Записва ги във файл, 
// чието име е подадено като първи параметър. 
// Замества символите за табулация с '>>>' и 
// резултата извежда на стандартния изход за грешки

int main(int argc,char *argv[])
{   
    if (argc != 1)
    {
        printf("\n expected 1 argument only");
        exit(1);
    }

    int f1d = open(argv[1], O_WRONLY|O_CREAT|O_APPEND, 0644);
    if(f1d == -1)
    {
        printf("\n couldn't open file %s\n", argv[0]);
        exit(1);
    }

    char buff;
    int read_buff=read(0, buff, 1);

    while(read_buff>0)
    {
        if(buff == '/t')
        {
            int write_in = write(f1d, ">>>", 3);
            write(2, write_in, 5);
        }
        else
        {
            int write_in = write(f1d, buff, 1);
            write(2, write_in, 5);
        }

        read_buff=read(0, buff, 1);
    }

    close(f1d);
}
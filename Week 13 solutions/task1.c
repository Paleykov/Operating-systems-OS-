#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

// Да се напише програма на C, която реализира командата cat (без параметри)

int main(int argc, char *argv[])
{
    if (argc != 1)
    {
        printf("\n expected one argument");
        exit(1);
    }

    char buffer[512];
    int nbytes = 0;

    while ((nbytes = read(0, buffer, 512)) > 0)
    {
        write(1, buffer, nbytes);
    }
}
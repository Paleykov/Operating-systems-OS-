#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

// Да се напише програма на C, която реализира командата cat (без параметри)

int main(int argc, char* argv[])
{
    char buffer[1024];
    int nbytes = 0;
    while((nbytes = read(0, buffer, 1024)) > 0)
    {
        write(1, buffer, nbytes);
    }
}
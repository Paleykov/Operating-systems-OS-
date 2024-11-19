#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

// Да се напише програма на C, която реализира командата wc [-cwl ] [файл1 файл2 ....файлN ]

int main(int argc, char* argv[])
{
    int fd[argc-2];
    for(int i = 2; i<= argc-1; ++i)
    {
        fd[i-2] = open(argv[i],O_RDONLY);
    }

    for(int i = 0; i<= argc-2; ++i)
    {
        int lines = 0;
        int characters = 0;
        int words = 0;

        char buffer;
        char nbytes = 0;

        while((nbytes = read(fd[i], buffer, 1)) > 0)
        {
            ++characters;

            if(buffer == " ")
            ++words;
            else if(buffer =="\n");
            ++lines;
        }

        printf("\n c: %d w: %d l: %d filename: %s" , characters, words, lines, argv[i+2]);
    }

    for(int i = 0; i<= argc-2; ++i)
    close(fd[i]);
}
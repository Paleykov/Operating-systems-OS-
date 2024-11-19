#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Напишете програма на Си, която печата символния низ „EXAMPLE“ 10 пъти на стандартния изход.

int main(argc, argv)
int argc; char* argv[];
{
    for(int i = 0; i < 10; ++i)
    {
        write(1, "EXAMPLE", sizeof("EXAMPLE"));
    }
}
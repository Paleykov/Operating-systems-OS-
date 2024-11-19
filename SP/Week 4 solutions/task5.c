#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Напишете програма на Си, която печата симолния низ „EXAMPLE“  
// и символния низ  „HELLO“ 10 пъти на стандартния изход, като между 
// тях се извеждат числата от 1 до 10.

int main(argc, argv)
int argc; char* argv[];
{
    for(int i = 0; i < 10; ++i)
    {   
        char snum[5];
        sprintf(snum, "%d", i);
        
        write(1, "EXAMPLE ", sizeof("EXAMPLE "));
        write(1, snum, sizeof("snum"));
        write(1, " HELLO", sizeof(" HELLO"));
    }
}
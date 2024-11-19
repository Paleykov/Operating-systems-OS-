#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Напишете програма на Си, която изпълнява команда извеждаща редовете, 
// в които се среща символния низ int в подадения като параметър файл.

int main(argc,argv)
int argc; char* argv[];
{
    execlp("grep","grep","int",argv[1],0);
}
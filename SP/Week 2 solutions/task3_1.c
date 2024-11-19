#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Създайте файл aa със съдържание английската азбука - извън програмата. Задачата отваря файла aa само за четене. 
// Чете от него чрез цикъл for и променлива в диапазон  от 5 до 1 в буфер с размер 16 байта. 
// Отпечатва с printf съдържанието на  буфера на всяка итерация.

char buffer[16];
int main(argc,argv)
int argc; char* argv[];
{
    int aa = open("aa", O_RDONLY);
    if(aa == -1)
    {
        printf("error opening file");
        exit(1);
    }

    for(int i = 8; i > 0; --i)
    {
        read(aa, buffer, i);
        printf("%s \n", buffer);
    }

    close(aa);
    return 0;
}
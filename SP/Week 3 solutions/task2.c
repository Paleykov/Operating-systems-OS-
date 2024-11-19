#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Отворете файла с 2 различни дескриптора за четене и писане. 
// Започвайки от  последните 2 символа напишете думата wxyz. 
// Запишете върху 5 и 6-тия символ от началото на файла - 
// цифрите 1 и 2. 
// Отпечатайте цялото съдържание на файла.

int main(argc, argv)
int argc; char* argv[];
{
    int fd_writing = open("f1", O_WRONLY, O_APPEND);
    if(fd_writing == -1)
    {
        printf("error opening file");
        exit(1);
    }
    int fd_reading = open("f1", O_RDONLY);
    if(fd_reading == -1)
    {
        printf("error opening file");
        exit(1);
    }

    lseek(fd_writing, -3, SEEK_END);
    write(fd_writing, "wxyz", 4);
    lseek(fd_writing, 4, SEEK_SET);
    write(fd_writing, "12", 2);

    char buffer[20];
    lseek(fd_reading,0, SEEK_SET);
    read(fd_reading, buffer, 20);
    write(1,buffer,20);

    close(fd_reading);
    close(fd_writing);
}
/*
===================================================================================================================
Name: 10.c
Author: Siddhesh Abhang
Description:- 
Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 17 Aug 2025
===================================================================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer1[10] = "ABCDEFGHIJ"; 
    char buffer2[10] = "1234567890";

   
    fd = open("testfile.txt", O_RDWR | O_CREAT, 0644);

    if (fd < 0) {
        perror("open");
        return 1;
    }

    write(fd, buffer1, 10);

    off_t offset = lseek(fd, 10, SEEK_CUR);

    if (offset == -1) {
        perror("lseek");
        close(fd);
        return 1;
    } else {
        printf("Current file offset after lseek: %ld\n", offset);
    }


    write(fd, buffer2, 10);


    close(fd);

    return 0;
}

/*
==================================================================================================================
Output:-
Current file offset after lseek: 300

Output after od -c testfile.txt:-
0000000    A   B   C   D   E   F   G   H   I   J  \0  \0  \0  \0  \0  \0
0000020   \0  \0  \0  \0   1   2   3   4   5   6   7   8   9   0
0000036

==================================================================================================================
*/

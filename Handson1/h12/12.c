/*
===================================================================================================================
Name: 12.c
Author: Siddhesh Abhang
Description:- 
Write a program to find out the opening mode of a file. Use fcntl.
Date: 19 Aug 2025
===================================================================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("test.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    int flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    int accessMode = flags & O_ACCMODE;
    if (accessMode == O_RDONLY)
        printf("File is opened in Read Only mode\n");
    else if (accessMode == O_WRONLY)
        printf("File is opened in Write Only mode\n");
    else if (accessMode == O_RDWR)
        printf("File is opened in Read Write mode\n");

    close(fd);
    return 0;
}

/*
==================================================================================================================

Output:-
File opened in READ WRITE mode

==================================================================================================================
*/


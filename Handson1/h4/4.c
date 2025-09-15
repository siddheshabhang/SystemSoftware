/*
===================================================================================================================
Name: 4.c
Author: Siddhesh Abhang
Description:- 
Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 12 Aug 2025
===================================================================================================================
*/

#include <stdio.h>
#include <fcntl.h>  
#include <unistd.h> 

int main() {
    int fd;

    fd = open("temp.txt", O_RDWR);
    if (fd == -1) {
        perror("Open failed");
    } else {
        printf("File opened successfully. File descriptor = %d\n", fd);
        close(fd);
    }

    fd = open("myfile.txt", O_RDWR | O_CREAT | O_EXCL, 0644);
    if (fd == -1) {
        perror("open with O_EXCL failed");
    } else {
        printf("File created (this should only succeed if file didn't exist). FD = %d\n", fd);
        close(fd);
    }

    return 0;
}

/*
==================================================================================================================

Output when no such file existed:-
Open failed: No such file or directory
File created (this should only succeed if file didn't exist). FD = 3

Output when file existed:-
File opened successfully. File descriptor = 3
open with O_EXCL failed: File exists

==================================================================================================================
*/


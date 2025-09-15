/*
===================================================================================================================
Name: 11.c
Author: Siddhesh Abhang
Description:- 
Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
Date: 19 Aug 2025
===================================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd, fd_dup1, fd_dup2, fd_dup3;


    fd = open("test.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }


    fd_dup1 = dup(fd);
    if (fd_dup1 < 0) {
        perror("dup");
        return 1;
    }


    fd_dup2 = dup2(fd, 100);
    if (fd_dup2 < 0) {
        perror("dup2");
        return 1;
    }


    fd_dup3 = fcntl(fd, F_DUPFD, 200);
    if (fd_dup3 < 0) {
        perror("fcntl");
        return 1;
    }

   
    write(fd, "Hello from fd\n", 14);

  
    write(fd_dup1, "Hello from dup\n", 15);

 
    write(fd_dup2, "Hello from dup2\n", 16);


    write(fd_dup3, "Hello from fcntl\n", 17);

    close(fd);
    close(fd_dup1);
    close(fd_dup2);
    close(fd_dup3);

    return 0;
}

/*
==================================================================================================================

Contents of test.txt:-
Hello from fd
Hello from dup
Hello from dup2
Hello from fcntl

==================================================================================================================
*/

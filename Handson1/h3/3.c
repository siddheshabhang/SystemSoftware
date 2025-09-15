/*
===================================================================================================================
Name: 3.c
Author: Siddhesh Abhang
Description:- 
Write a program to create a file and print the file descriptor value. Use creat() system call
Date: 12 Aug 2025
===================================================================================================================
*/

#include <stdio.h>
#include <fcntl.h>  
#include <unistd.h> 

int main() {
    int fd;

    fd = creat("siddhesh.txt", 0644);

    if (fd == -1) {
        perror("creat failed");
    } else {
        printf("File created successfully. File descriptor = %d\n", fd);
        close(fd); 
    }

    return 0;
}

/*
==================================================================================================================

Output:-
File created successfully. File descriptor = 3

Output after ls -lh:-
Permissions Size User           Date Modified Name
.rw-r--r--@  836 siddheshabhang  7 Sep 13:28  3.c
.rw-r--r--@  362 siddheshabhang 18 Aug 19:31  h3.txt
.rwxr-xr-x@  34k siddheshabhang  7 Sep 13:25  output3
.rw-r--r--@    0 siddheshabhang  7 Sep 13:28  siddhesh.txt

==================================================================================================================
*/

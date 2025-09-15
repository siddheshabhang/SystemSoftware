/*
===================================================================================================================
Name: 1c.c
Author: Siddhesh Abhang
Description:-
Create the following types of a files using syscall
FIFO (mkfifo Library Function or mknod system call)
Date: 12 Aug 2025
===================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
int main(){
    if (mkfifo("myfifo", 0666) == -1) {
        perror("mkfifo failed");
    }
     else {
        printf("FIFO created: myfifo\n");
    }

    return 0;
}

/*
==================================================================================================================

Output:-
FIFO created: myfifo

==================================================================================================================
*/


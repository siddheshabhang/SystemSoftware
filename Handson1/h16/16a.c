/*
===================================================================================================================
Name: 16a.c
Author: Siddhesh Abhang.
Description:-
Write a program to perform mandatory locking
Implement write lock
Date: 2 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    int fd;
    struct flock lock;
    fd = open("testfile.txt", O_RDWR | O_CREAT, 0666);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("Trying to acquire write lock...\n");
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        exit(1);
    }

    printf("Write lock acquired. Press Enter to release...\n");
    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Lock released.\n");
    close(fd);
    return 0;
}

/*
==================================================================================================================

Output from Terminal 1:-
Trying to acquire read lock...
Write lock acquired. Press Enter to release...

Output from Terminal 2:-
Trying to acquire write lock...

==================================================================================================================
*/

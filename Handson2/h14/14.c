/*
============================================================================
Name : 14.c
Author : Siddhesh Abhang.
Description : 
Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: 21th September 2025
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int fd[2];                 // fd[0] for read, fd[1] for write
    char write_msg[] = "Hello Pipe!";
    char read_msg[100];

    // Create pipe
    if (pipe(fd) == -1) {
        perror("Pipe failed");
        exit(1);
    }

    // Write to pipe
    write(fd[1], write_msg, strlen(write_msg) + 1);

    // Read from pipe
    read(fd[0], read_msg, sizeof(read_msg));

    // Display on monitor
    printf("Message read from pipe: %s\n", read_msg);

    // Close pipe ends
    close(fd[0]);
    close(fd[1]);

    return 0;
}

/*
============================================================================

Output:-
Message read from pipe: Hello Pipe!

============================================================================
*/

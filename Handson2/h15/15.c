/*
============================================================================
Name : 15.c
Author : Siddhesh Abhang.
Description : 
Write a simple program to send some data from parent to the child process.
Date: 21th September 2025
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int fd[2];
    pid_t pid;
    char write_msg[] = "Hi Child, I am your parent!";
    char read_msg[100];

    // Create pipe
    if (pipe(fd) == -1) {
        perror("pipe failed");
        exit(1);
    }

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid > 0) {  // Parent process
        close(fd[0]);  // Close unused read end
        write(fd[1], write_msg, strlen(write_msg) + 1);
        close(fd[1]);  // Close write end after sending
    } 
    else {  // Child process
        close(fd[1]);  // Close unused write end
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);
        close(fd[0]);  // Close read end
    }

    return 0;
}

/*
============================================================================

Output:-
Child received: Hi Child, I am your parent!

============================================================================
*/

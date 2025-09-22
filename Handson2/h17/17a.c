/*
============================================================================
Name : 17a.c
Author : Siddhesh Abhang.
Description : 
Write a program to execute ls -l | wc
* Use dup
Date: 22th September 2025
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    else if (pid == 0) {
        // ----- Child process -----
        close(STDOUT_FILENO);   // close stdout (fd = 1)
        dup(fd[1]);             // now pipe write end becomes stdout

        close(fd[0]); // not used
        close(fd[1]); // after dup

        execlp("ls", "ls", "-l", NULL);
        perror("execlp"); 
        exit(1);
    }
    else {
        // ----- Parent process -----
        close(STDIN_FILENO);    // close stdin (fd = 0)
        dup(fd[0]);             // now pipe read end becomes stdin

        close(fd[1]); // not used
        close(fd[0]); // after dup

        execlp("wc", "wc", NULL);
        perror("execlp"); 
        exit(1);
    }

    return 0;
}

/*
============================================================================

Output:-
       5      38     257

============================================================================
*/

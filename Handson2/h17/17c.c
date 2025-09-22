/*
============================================================================
Name : 17c.c
Author : Siddhesh Abhang.
Description : 
Write a program to execute ls -l | wc
* Use fcntl
Date: 22th September 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

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

    if (pid == 0) {  
        // ---- Child process: executes "ls -l" ----
        close(fd[0]);                  // close read end

        close(STDOUT_FILENO);          // free stdout (fd=1)
        if (fcntl(fd[1], F_DUPFD, STDOUT_FILENO) == -1) {
            perror("fcntl");
            exit(1);
        }
        close(fd[1]);                  // close extra fd

        execlp("ls", "ls", "-l", NULL);
        perror("execlp");              // exec failed
        exit(1);

    } else {  
        // ---- Parent process: executes "wc" ----
        close(fd[1]);                  // close write end

        close(STDIN_FILENO);           // free stdin (fd=0)
        if (fcntl(fd[0], F_DUPFD, STDIN_FILENO) == -1) {
            perror("fcntl");
            exit(1);
        }
        close(fd[0]);                  // close extra fd

        execlp("wc", "wc", NULL);
        perror("execlp");
        exit(1);
    }

    return 0;
}
/*
============================================================================

Output:-
       4      29     195

============================================================================
*/

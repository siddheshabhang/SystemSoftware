/*
============================================================================
Name : 17b.c
Author : Siddhesh Abhang.
Description : 
Write a program to execute ls -l | wc
* Use dup2
Date: 22th September 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
        close(fd[0]);              // close read end
        dup2(fd[1], STDOUT_FILENO); // redirect stdout to pipe
        close(fd[1]);              // close extra fd
        execlp("ls", "ls", "-l", NULL);
        perror("execlp");          // if execlp fails
        exit(1);
    } else {  
        // ---- Parent process: executes "wc" ----
        close(fd[1]);              // close write end
        dup2(fd[0], STDIN_FILENO);  // redirect stdin to pipe
        close(fd[0]);              // close extra fd
        execlp("wc", "wc", NULL);
        perror("execlp");
        exit(1);
    }

    return 0;
}
/*
===========================================================================
Output:-
       4      29     195

============================================================================
*/

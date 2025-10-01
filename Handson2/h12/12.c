/*
============================================================================
Name : 12.c
Author : Siddhesh Abhang.
Description:- Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date: 1st October 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid > 0) {
        // Parent process
        printf("Parent process PID: %d\n", getpid());
        sleep(10); // Give child time to kill parent
        printf("Parent is still alive (should not reach here if child kills parent)\n");
    } 
    else {
        // Child process
        printf("Child process PID: %d, Parent PID: %d\n", getpid(), getppid());

        sleep(2); // Small delay to ensure parent prints first

        printf("Child is killing parent now...\n");
        kill(getppid(), SIGKILL);  // Send SIGKILL to parent

        printf("Child continues running. New parent PID: %d\n", getppid());
        sleep(5); // Keep child alive to show orphaning
    }

    return 0;
}


/*
============================================================================

Output:-
Parent process PID: 16398
Child process PID: 16399, Parent PID: 16398
Child is killing parent now...
Child continues running. New parent PID: 16398
[1]    16398 killed     ./a.out

============================================================================
*/

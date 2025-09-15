/*
===================================================================================================================
Name: 23.c
Author: Siddhesh Abhang
Description:-
Write a program to create a Zombie state of the running program.
Date: 3 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }
    else if (pid == 0) {
        printf("Child process (PID = %d) exiting...\n", getpid());
        exit(0);
    }
    else {
        printf("Parent process (PID = %d) sleeping...\n", getpid());
        sleep(30);
        printf("Parent exiting...\n");
    }

    return 0;
}

/*
==================================================================================================================

Output:-
Parent process (PID = 379) sleeping...
Child process (PID = 380) exiting...

Output after ps -l:-
 UID   PID  PPID        F CPU PRI NI       SZ    RSS WCHAN     S             ADDR TTY           TIME CMD
  501   221 96038     4006   0  31  0 410593024   1168 -      S+                  0 ttys000    0:00.01 ./a.out
  501   222   221     2006   0   0  0        0      0 -      Z+                  0 ttys000    0:00.00 <defunct>
  501 96038 96036     4006   0  31  0 411185056   8992 -      S                   0 ttys000    0:17.98 -zsh

==================================================================================================================
*/

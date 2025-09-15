/*
===================================================================================================================
Name: 25.c
Author: Siddhesh Abhang
Description:-
Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 2 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t cpid1, cpid2, cpid3;
    int status;
  
    cpid1 = fork();
    if (cpid1 == 0) {
        printf("Child 1 (PID = %d) running...\n", getpid());
        sleep(2);
        printf("Child 1 (PID = %d) exiting.\n", getpid());
        exit(1);
    }

      cpid2 = fork();
    if (cpid2 == 0) {
        printf("Child 2 (PID = %d) running...\n", getpid());
        sleep(4);
        printf("Child 2 (PID = %d) exiting.\n", getpid());
        exit(2);
    }

    cpid3 = fork();
    if (cpid3 == 0) {
        printf("Child 3 (PID = %d) running...\n", getpid());
        sleep(6);
        printf("Child 3 (PID = %d) exiting.\n", getpid());
        exit(3);
    }

    pid_t waited_pid = waitpid(cpid1, &status, 0);
    if (waited_pid == -1) {
        perror("waitpid failed");
    } else {
        if (WIFEXITED(status)) {
            printf("Parent: Child 1 (PID = %d) terminated with exit status %d\n",
                   waited_pid, WEXITSTATUS(status));
        }
    }

	 printf("Parent (PID = %d) exiting.\n", getpid());

    return 0;
}

/*
==================================================================================================================

Output:-
Child 1 (PID = 2137) running...
Child 2 (PID = 2138) running...
Child 3 (PID = 2139) running...
Child 1 (PID = 2137) exiting.
Parent: Child 1 (PID = 2137) terminated with exit status 1
Parent (PID = 2136) exiting.
Child 2 (PID = 2138) exiting.                      ─╯
Child 3 (PID = 2139) exiting.

==================================================================================================================
*/

/*
===================================================================================================================
Name: 21.c
Author: Siddhesh Abhang
Description:-
Find out the priority of your running program. Modify the priority with nice command.
Date: 3 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
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

        printf("I am the child process. My PID = %d, My Parent's PID = %d\n",
               getpid(), getppid());
    }
    else {
        printf("I am the parent process. My PID = %d, My Child's PID = %d\n",getpid(), pid);
    }

    return 0;
}

/*
==================================================================================================================
Output:- 
I am the parent process. My PID = 99224, My Child's PID = 99226
I am the child process. My PID = 99226, My Parent's PID = 1

==================================================================================================================
*/

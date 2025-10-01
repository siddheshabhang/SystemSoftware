/*
============================================================================
Name : 13_send.c
Author : Siddhesh Abhang.
Description:-  
Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 1st October 2025
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <PID>\n", argv[0]);
        return 1;
    }

    pid_t pid = atoi(argv[1]);
    printf("Sending SIGSTOP to PID %d\n", pid);

    kill(pid, SIGSTOP); // Stops the process
    printf("SIGSTOP sent. Process should be stopped now.\n");

    return 0;
}

/*
============================================================================

Output for ./send 16793:-
Sending SIGSTOP to PID 16793
SIGSTOP sent. Process should be stopped now.

============================================================================
*/

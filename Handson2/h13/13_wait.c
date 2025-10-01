/*
============================================================================
Name : 13_wait.c
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
#include <unistd.h>

void sig_handler(int signum) {
    printf("Caught signal %d\n", signum);
}

int main() {
    printf("Process PID: %d\n", getpid());
    
    // Attempt to catch SIGSTOP
    signal(SIGSTOP, sig_handler); // Will NOT work

    printf("Waiting for SIGSTOP...\n");

    while(1) {
        sleep(1);
    }

    return 0;
}

/*
============================================================================

Output for ./wait :-
Process PID: 16793
Waiting for SIGSTOP...
[1]  + 16793 suspended (signal)  ./wait

============================================================================
*/

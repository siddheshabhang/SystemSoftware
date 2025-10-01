/*
============================================================================
Name : 10b.c
Author : Siddhesh Abhang.
Description:- Write a separate program using sigaction system call to catch the following signals.
b. SIGINT
Date: 1st October 2025
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sigint_handler(int signum, siginfo_t *info, void *context) {
    printf("\nCaught SIGINT (Ctrl+C)! Exiting...\n");
    exit(0);
}

int main() {
    struct sigaction sa;
    sa.sa_sigaction = sigint_handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGINT, &sa, NULL);

    printf("Press Ctrl+C to trigger SIGINT...\n");
    while(1) {
        sleep(1);
    }

    return 0;
}

/*
============================================================================

Output:-
Press Ctrl+C to trigger SIGINT...
^C
Caught SIGINT (Ctrl+C)! Exiting...

============================================================================
*/

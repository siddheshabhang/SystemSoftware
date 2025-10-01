/*
============================================================================
Name : 10c.c
Author : Siddhesh Abhang.
Description:- Write a separate program using sigaction system call to catch the following signals.
c. SIGFPE
Date: 1st October 2025
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigfpe_handler(int signum, siginfo_t *info, void *context) {
    printf("Caught SIGFPE!\n");
    exit(1);
}

int main() {
    struct sigaction sa;
    sa.sa_sigaction = sigfpe_handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGFPE, &sa, NULL);

    printf("Triggering SIGFPE using raise()...\n");

    // Trigger SIGFPE reliably on macOS
    raise(SIGFPE);

    return 0;
}

/*
============================================================================

Output:-
Triggering SIGFPE using raise()...
Caught SIGFPE!

============================================================================
*/

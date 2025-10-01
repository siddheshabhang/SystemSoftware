/*
============================================================================
Name : 8c.c
Author : Siddhesh Abhang.
Description:-
Write a separate program using signal system call to catch the following signals.
c. SIGFPE
Date: 1st October 2025
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigfpe_handler(int signum) {
    printf("Caught SIGFPE!\n");
    exit(0);
}

int main() {
    signal(SIGFPE, sigfpe_handler);
    printf("Raising SIGFPE...\n");
    raise(SIGFPE); // Guaranteed to trigger handler
    return 0;
}

/*
============================================================================

Output:-
Raising SIGFPE...
Caught SIGFPE!

============================================================================
*/

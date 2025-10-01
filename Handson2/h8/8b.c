/*
============================================================================
Name : 8b.c
Author : Siddhesh Abhang.
Description:-
Write a separate program using signal system call to catch the following signals.
b. SIGINT
Date: 1st October 2025
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sigint_handler(int signum) {
    printf("\nCaught SIGINT (Ctrl+C)!\n");
    exit(0);
}

int main() {
    signal(SIGINT, sigint_handler);

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
Caught SIGINT (Ctrl+C)!

============================================================================
*/

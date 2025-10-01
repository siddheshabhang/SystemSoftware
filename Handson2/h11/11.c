/*
============================================================================
Name : 11.c
Author : Siddhesh Abhang.
Description:- Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date: 1st October 2025
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    struct sigaction sa_ignore, sa_default;

    // Step 1: Ignore SIGINT
    sa_ignore.sa_handler = SIG_IGN;
    sigemptyset(&sa_ignore.sa_mask);
    sa_ignore.sa_flags = 0;
    sigaction(SIGINT, &sa_ignore, NULL);

    printf("SIGINT (Ctrl+C) is now ignored for 5 seconds. Try pressing Ctrl+C...\n");
    sleep(5);

    // Step 2: Reset SIGINT to default
    sa_default.sa_handler = SIG_DFL;
    sigemptyset(&sa_default.sa_mask);
    sa_default.sa_flags = 0;
    sigaction(SIGINT, &sa_default, NULL);

    printf("SIGINT has been reset to default action. Press Ctrl+C to exit.\n");

    // Infinite loop to allow testing
    while(1) {
        sleep(1);
    }

    return 0;
}

/*
============================================================================

Output:-
SIGINT (Ctrl+C) is now ignored for 5 seconds. Try pressing Ctrl+C...
^C
SIGINT has been reset to default action. Press Ctrl+C to exit.
^C

============================================================================
*/

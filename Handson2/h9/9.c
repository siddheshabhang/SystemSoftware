/*
============================================================================
Name : 9.c
Author : Siddhesh Abhang.
Description:-
Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
Date: 1st October 2025
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    printf("Press Ctrl+C now. SIGINT is ignored for 5 seconds...\n");

    // Ignore SIGINT
    signal(SIGINT, SIG_IGN);

    sleep(5);  // During this time, Ctrl+C will be ignored

    printf("Now resetting SIGINT to default action. Press Ctrl+C to exit.\n");

    // Reset SIGINT to default
    signal(SIGINT, SIG_DFL);

    // Loop to allow user to test default action
    while(1) {
        sleep(1);
    }

    return 0;
}

/*
============================================================================

Output:-
Press Ctrl+C now. SIGINT is ignored for 5 seconds...
^C
Now resetting SIGINT to default action. Press Ctrl+C to exit.
^C

============================================================================
*/

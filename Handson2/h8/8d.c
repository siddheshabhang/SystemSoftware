/*
============================================================================
Name : 8d.c
Author : Siddhesh Abhang.
Description:-
Write a separate program using signal system call to catch the following signals.
d. SIGALRM (use alarm system call)
Date: 1st October 2025
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sigalrm_handler(int signum) {
    printf("\nCaught SIGALRM! Alarm triggered.\n");
}

int main() {
    int seconds;
    printf("Enter number of seconds for alarm: ");
    if (scanf("%d", &seconds) != 1 || seconds <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    signal(SIGALRM, sigalrm_handler);
    alarm(seconds);
    printf("Alarm set for %d seconds...\n", seconds);

    pause(); // Wait for signal
    return 0;
}

/*
============================================================================

Output:-
Enter number of seconds for alarm: 10
Alarm set for 10 seconds...

Caught SIGALRM! Alarm triggered.


============================================================================
*/

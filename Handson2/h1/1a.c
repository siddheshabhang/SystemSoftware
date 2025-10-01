/*
============================================================================
Name : 1a.c
Author : Siddhesh Abhang.
Description:-
Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
Date: 1st October 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int sig) {
    printf("ITIMER_REAL expired!\n");
}

int main() {
    struct itimerval timer;

    signal(SIGALRM, handler);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    setitimer(ITIMER_REAL, &timer, NULL);

    while (1) pause();  // wait for signal
    return 0;
}

/*
============================================================================

Output after 10sec:-
ITIMER_REAL expired!

Output after 10sec + 10microsec:-
ITIMER_REAL expired!

============================================================================
*/

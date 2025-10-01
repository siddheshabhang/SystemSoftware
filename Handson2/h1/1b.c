/*
============================================================================
Name : 1b.c
Author : Siddhesh Abhang.
Description:-
Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
b. ITIMER_VIRTUAL
Date: 1st October 2025
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int sig) {
    printf("ITIMER_VIRTUAL expired!\n");
}

int main() {
    struct itimerval timer;

    signal(SIGVTALRM, handler);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    while (1) {
        // busy loop to consume CPU (virtual time decreases only when running)
    }
    return 0;
}

/*
============================================================================

Output:-
ITIMER_VIRTUAL expired!

============================================================================
*/

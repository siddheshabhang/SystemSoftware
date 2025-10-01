/*
============================================================================
Name : 1c.c
Author : Siddhesh Abhang.
Description:-
Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
c .ITIMER_PROF
Date: 1st October 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int sig) {
    printf("ITIMER_PROF expired!\n");
}

int main() {
    struct itimerval timer;

    signal(SIGPROF, handler);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    setitimer(ITIMER_PROF, &timer, NULL);

    while (1) {
        // mixture of CPU + system calls for prof timer to tick
        for (volatile long i = 0; i < 1000000; i++);
        usleep(1000);
    }
    return 0;
}

/*
============================================================================

Output:-
ITIMER_PROF expired!

============================================================================
*/

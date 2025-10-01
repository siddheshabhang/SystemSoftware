/*
============================================================================
Name : 8g.c
Author : Siddhesh Abhang.
Description:-
Write a separate program using signal system call to catch the following signals.
g. SIGPROF (use setitimer system call)
Date: 1st October 2025
============================================================================
*/


#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

void sigprof_handler(int signum) {
    printf("\nCaught SIGPROF (profiling timer)!\n");
    _exit(0);
}

int main() {
    int usec;
    printf("Enter microseconds for profiling timer: ");
    scanf("%d", &usec);

    signal(SIGPROF, sigprof_handler);

    struct itimerval timer;
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = usec;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &timer, NULL);

    // Busy loop to simulate CPU + system time
    while(1) {}
}

/*
============================================================================

Output:-
Enter microseconds for profiling timer: 500000

Caught SIGPROF (profiling timer)!

============================================================================
*/

/*
============================================================================
Name : 8f.c
Author : Siddhesh Abhang.
Description:-
Write a separate program using signal system call to catch the following signals.
f. SIGVTALRM (use setitimer system call)
Date: 1st October 2025
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void sigvtalrm_handler(int signum) {
    printf("\nCaught SIGVTALRM (virtual timer)!\n");
    _exit(0);
}

int main() {
    int usec;
    printf("Enter microseconds for virtual timer: ");
    scanf("%d", &usec);

    signal(SIGVTALRM, sigvtalrm_handler);

    struct itimerval timer;
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = usec;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    // Busy loop to consume CPU and trigger virtual timer
    while(1) {}
}

/*
============================================================================

Output:-
Enter microseconds for virtual timer: 500000

Caught SIGVTALRM (virtual timer)!

============================================================================
*/

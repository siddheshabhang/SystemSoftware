/*
============================================================================
Name : 8e.c
Author : Siddhesh Abhang.
Description:-
Write a separate program using signal system call to catch the following signals.
e. SIGALRM (use setitimer system call)
Date: 1st October 2025
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>

void sigalrm_handler(int signum) {
    printf("\nCaught SIGALRM (setitimer)!\n");
}

int main() {
    int sec, usec;
    printf("Enter seconds for alarm: ");
    scanf("%d", &sec);
    printf("Enter microseconds for alarm: ");
    scanf("%d", &usec);

    signal(SIGALRM, sigalrm_handler);

    struct itimerval timer;
    timer.it_value.tv_sec = sec;
    timer.it_value.tv_usec = usec;
    timer.it_interval.tv_sec = 0;  // One-shot
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);
    printf("Alarm set for %d seconds and %d microseconds...\n", sec, usec);

    pause();
    return 0;
}

/*
============================================================================

Output:-
Enter seconds for alarm: 5
Enter microseconds for alarm: 2
Alarm set for 5 seconds and 2 microseconds...

Caught SIGALRM (setitimer)!

============================================================================
*/

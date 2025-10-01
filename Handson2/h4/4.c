/*
============================================================================
Name : 4.c
Author : Siddhesh Abhang.
Description:-
Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
Date: 1st October 2025
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main() {
    struct timespec start, end;
    int i;

    // Record start time
    clock_gettime(CLOCK_MONOTONIC, &start);

    // Perform 100 getppid() calls
    for (i = 0; i < 100; i++) {
        getppid();
    }

    // Record end time
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculate elapsed time in nanoseconds
    long seconds = end.tv_sec - start.tv_sec;
    long nanoseconds = end.tv_nsec - start.tv_nsec;
    long elapsed = seconds * 1e9 + nanoseconds;

    printf("Time taken for 100 getppid() calls: %ld nanoseconds\n", elapsed);

    return 0;
}
/*
============================================================================

Output:-
Time taken for 100 getppid() calls: 38000 nanoseconds

============================================================================
*/

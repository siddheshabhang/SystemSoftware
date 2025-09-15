/*
===================================================================================================================
Name: 16b.c
Author: Siddhesh Abhang
Description:-
Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 2 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main() {
    struct timespec start, end;
    pid_t pid;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

    pid = getpid(); 

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    long seconds = end.tv_sec - start.tv_sec;
    long nanoseconds = end.tv_nsec - start.tv_nsec;
    long total_ns = seconds * 1000000000L + nanoseconds;

    printf("Process ID: %d\n", pid);
    printf("Time taken by getpid(): %ld nanoseconds\n", total_ns);

    return 0;
}

/*
==================================================================================================================

Output:-
Process ID: 98570
Time taken by getpid(): 125 nanoseconds

==================================================================================================================
*/

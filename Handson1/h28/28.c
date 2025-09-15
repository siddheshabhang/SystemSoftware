/*
===================================================================================================================
Name: 28.c
Author: Siddhesh Abhang
Description:-
Write a program to get maximum and minimum real time priority.
Date: 6 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <sched.h>

int main() {
    int max_priority, min_priority;

    max_priority = sched_get_priority_max(SCHED_FIFO);

    min_priority = sched_get_priority_min(SCHED_FIFO);

    printf("Maximum real-time priority (SCHED_FIFO): %d\n", max_priority);
    printf("Minimum real-time priority (SCHED_FIFO): %d\n", min_priority);

    return 0;
}

/*
==================================================================================================================

Output:-
Maximum real-time priority (SCHED_FIFO): 47
Minimum real-time priority (SCHED_FIFO): 15

==================================================================================================================
*/


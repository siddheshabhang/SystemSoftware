/*
===================================================================================================================
Name: 29.c
Author: Siddhesh Abhang
Description:- 
Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO, SCHED_RR)
Date: 6 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <errno.h>
#include <string.h>

void print_policy(int policy) {
    switch (policy) {
        case SCHED_OTHER:
            printf("Current Policy: SCHED_OTHER (Normal Time-Sharing)\n");
            break;
        case SCHED_FIFO:
            printf("Current Policy: SCHED_FIFO (First-In-First-Out Real-Time)\n");
            break;
        case SCHED_RR:
            printf("Current Policy: SCHED_RR (Round-Robin Real-Time)\n");
            break;
        default:
            printf("Current Policy: Unknown (%d)\n", policy);
    }
}

int main() {
    pid_t pid = getpid();

    int policy = sched_getscheduler(pid);
    if (policy == -1) {
        perror("sched_getscheduler failed");
        exit(1);
    }
    print_policy(policy);

    struct sched_param param;
    param.sched_priority = 10;

    if (sched_setscheduler(pid, SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler (SCHED_FIFO) failed");
    } else {
        printf("Scheduling policy changed to SCHED_FIFO successfully.\n");
    }

    policy = sched_getscheduler(pid);
    print_policy(policy);

    return 0;
}

/*
==================================================================================================================

Output:-
Current Policy: SCHED_OTHER (Normal Time-Sharing)
Scheduling policy changed to SCHED_FIFO successfully.
Current Policy: SCHED_FIFO (First-In-First-Out Real-Time)

==================================================================================================================
*/


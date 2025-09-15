/*
===================================================================================================================
Name: 20.c
Author: Siddhesh Abhang
Description:-
Find out the priority of your running program. Modify the priority with nice command.
Date: 2 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>

int main() {
    int priority;

    priority = getpriority(PRIO_PROCESS, 0);
    if (priority == -1 && errno != 0) {
        perror("getpriority failed");
        return 1;
    }

    printf("Current process ID: %d\n", getpid());
    printf("Current priority (nice value): %d\n", priority);

    if (nice(5) == -1 && errno != 0) {
        perror("nice failed");
        return 1;
    }

     priority = getpriority(PRIO_PROCESS, 0);
    printf("New priority (nice value): %d\n", priority);

    return 0;
}

/*
==================================================================================================================

Output:-
Current process ID: 98845
Current priority (nice value): 0
New priority (nice value): 5

==================================================================================================================
*/

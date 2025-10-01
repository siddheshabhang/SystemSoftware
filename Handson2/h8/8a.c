/*
============================================================================
Name : 8a.c
Author : Siddhesh Abhang.
Description:-
Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
Date: 1st October 2025
============================================================================
*/


#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigsegv_handler(int signum) {
    printf("Caught SIGSEGV (Segmentation Fault)!\n");
    exit(1);
}

int main() {
    signal(SIGSEGV, sigsegv_handler);

    // Cause segmentation fault
    int *ptr = NULL;
    *ptr = 10;  // Trigger SIGSEGV

    return 0;
}

/*
============================================================================

Output:-
Caught SIGSEGV (Segmentation Fault)!

============================================================================
*/

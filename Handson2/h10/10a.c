/*
============================================================================
Name : 10a.c
Author : Siddhesh Abhang.
Description:- Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
Date: 1st October 2025
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigsegv_handler(int signum, siginfo_t *info, void *context) {
    printf("Caught SIGSEGV (Segmentation Fault)!\n");
    exit(1);
}

int main() {
    struct sigaction sa;
    sa.sa_sigaction = sigsegv_handler;
    sa.sa_flags = SA_SIGINFO;  // To use sa_sigaction
    sigemptyset(&sa.sa_mask);

    sigaction(SIGSEGV, &sa, NULL);

    // Cause segmentation fault
    int *ptr = NULL;
    *ptr = 10;

    return 0;
}


/*
============================================================================

Output:-


============================================================================
*/

/*
============================================================================
Name : 3.c
Author : Siddhesh Abhang.
Description:-
Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 1st October 2025
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

int main() {
    struct rlimit rl;

    // Get current file size limit
    if (getrlimit(RLIMIT_FSIZE, &rl) == -1) {
        perror("getrlimit");
        exit(1);
    }

    printf("Current File Size Limit: Soft = %ld, Hard = %ld\n",
           (rl.rlim_cur == RLIM_INFINITY) ? -1 : rl.rlim_cur,
           (rl.rlim_max == RLIM_INFINITY) ? -1 : rl.rlim_max);

    // Set new file size limit (e.g., 1 MB = 1024*1024 bytes)
    rl.rlim_cur = 1024 * 1024;  
    rl.rlim_max = 1024 * 1024;

    if (setrlimit(RLIMIT_FSIZE, &rl) == -1) {
        perror("setrlimit");
        exit(1);
    }

    // Verify the change
    if (getrlimit(RLIMIT_FSIZE, &rl) == -1) {
        perror("getrlimit");
        exit(1);
    }

    printf("New File Size Limit:     Soft = %ld, Hard = %ld\n",
           (rl.rlim_cur == RLIM_INFINITY) ? -1 : rl.rlim_cur,
           (rl.rlim_max == RLIM_INFINITY) ? -1 : rl.rlim_max);

    return 0;
}

/*
============================================================================

Output:-
Current File Size Limit: Soft = -1, Hard = -1
New File Size Limit:     Soft = 1048576, Hard = 1048576

============================================================================
*/

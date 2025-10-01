/*
============================================================================
Name : 2.c
Author : Siddhesh Abhang.
Description:-
Write a program to print the system resource limits. Use getrlimit system call.
Date: 1st October 2025
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

void print_limit(int resource, const char *name) {
    struct rlimit rl;
    if (getrlimit(resource, &rl) == 0) {
        printf("%-25s : Soft = %ld, Hard = %ld\n", 
               name,
               (rl.rlim_cur == RLIM_INFINITY) ? -1 : rl.rlim_cur,
               (rl.rlim_max == RLIM_INFINITY) ? -1 : rl.rlim_max);
    } else {
        perror("getrlimit");
    }
}

int main() {
    printf("System Resource Limits:\n\n");

    print_limit(RLIMIT_CPU, "CPU time (seconds)");
    print_limit(RLIMIT_FSIZE, "File size (bytes)");
    print_limit(RLIMIT_DATA, "Data segment (bytes)");
    print_limit(RLIMIT_STACK, "Stack size (bytes)");
    print_limit(RLIMIT_CORE, "Core file size (bytes)");
    print_limit(RLIMIT_NOFILE, "Open files");
    print_limit(RLIMIT_AS, "Address space (bytes)");
    print_limit(RLIMIT_NPROC, "Max processes");
    print_limit(RLIMIT_MEMLOCK, "Locked memory (bytes)");

    return 0;
}

/*
============================================================================

Output:-
System Resource Limits:

CPU time (seconds)        : Soft = -1, Hard = -1
File size (bytes)         : Soft = -1, Hard = -1
Data segment (bytes)      : Soft = -1, Hard = -1
Stack size (bytes)        : Soft = 8372224, Hard = 67092480
Core file size (bytes)    : Soft = 0, Hard = -1
Open files                : Soft = 256, Hard = -1
Address space (bytes)     : Soft = -1, Hard = -1
Max processes             : Soft = 1333, Hard = 1333
Locked memory (bytes)     : Soft = -1, Hard = -1

============================================================================
*/

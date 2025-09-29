/*
============================================================================
Name : 23.c
Author : Siddhesh Abhang.
Description : 
Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 28th September 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void) {
    struct rlimit rl;

    // 1. Maximum number of files a process can open
    if (getrlimit(RLIMIT_NOFILE, &rl) == 0) {
        printf("Max files a process can open (soft limit): %ld\n", (long) rl.rlim_cur);
        printf("Max files a process can open (hard limit): %ld\n", (long) rl.rlim_max);
    } else {
        perror("getrlimit");
    }

    // 2. Pipe buffer size
#if defined(__linux__)
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }
#ifdef F_GETPIPE_SZ
    int size = fcntl(fd[0], F_GETPIPE_SZ);
    if (size == -1) {
        perror("fcntl");
    } else {
        printf("Pipe (circular buffer) size: %d bytes\n", size);
    }
#else
    printf("Pipe buffer size query not supported on this Linux system.\n");
#endif
    close(fd[0]);
    close(fd[1]);

#elif defined(__APPLE__)
    // macOS has fixed pipe size
    printf("Pipe (circular buffer) size: 16384 bytes (fixed on macOS)\n");

#else
    printf("Pipe buffer size query not supported on this OS.\n");
#endif

    return 0;
}

/*
============================================================================

Output:-
Max files a process can open (soft limit): 256
Max files a process can open (hard limit): 9223372036854775807
Pipe (circular buffer) size: 16384 bytes (fixed on macOS)

============================================================================
*/

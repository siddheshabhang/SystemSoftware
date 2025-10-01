/*
============================================================================
Name : 5.c
Author : Siddhesh Abhang.
Description:-
Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.
system call. Use time stamp counter.
Date: 1st October 2025
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysctl.h>

int main() {
    // Basic system limits
    printf("a. Maximum length of arguments to exec: %ld\n", sysconf(_SC_ARG_MAX));
    printf("b. Maximum number of simultaneous processes per user id: %ld\n", sysconf(_SC_CHILD_MAX));
    printf("c. Number of clock ticks (jiffies) per second: %ld\n", sysconf(_SC_CLK_TCK));
    printf("d. Maximum number of open files: %ld\n", sysconf(_SC_OPEN_MAX));
    
    long page_size = sysconf(_SC_PAGESIZE);
    printf("e. Size of a page: %ld bytes\n", page_size);

    // Total physical memory
    int64_t total_mem;
    size_t len = sizeof(total_mem);
    int mib[2] = {CTL_HW, HW_MEMSIZE};
    if (sysctl(mib, 2, &total_mem, &len, NULL, 0) == 0) {
        printf("f. Total number of pages (approx): %lld\n", total_mem / page_size);
    } else {
        printf("f. Total number of pages: Not available\n");
    }

    // Currently available pages (optional / not implemented)
    printf("g. Number of currently available pages: Not shown\n");

    return 0;
}


/*
============================================================================

Output:-
a. Maximum length of arguments to exec: 1048576
b. Maximum number of simultaneous processes per user id: 1333
c. Number of clock ticks (jiffies) per second: 100
d. Maximum number of open files: 256
e. Size of a page: 16384 bytes
f. Total number of pages (approx): 524288
g. Number of currently available pages: Not shown

============================================================================
*/
